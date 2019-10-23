/**********************************************************************************
* Blueprint Reality Inc. CONFIDENTIAL
* 2019 Blueprint Reality Inc.
* All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains, the property of
* Blueprint Reality Inc. and its suppliers, if any.  The intellectual and
* technical concepts contained herein are proprietary to Blueprint Reality Inc.
* and its suppliers and may be covered by Patents, pending patents, and are
* protected by trade secret or copyright law.
*
* Dissemination of this information or reproduction of this material is strictly
* forbidden unless prior written permission is obtained from Blueprint Reality Inc.
***********************************************************************************/

#include "MixCastCamera.h"

#include "MixCast.h"
#include "MixCastSdkActor.h"
#include "ServiceCommunicator.h"
#include "Utility/MathUtil.hpp"
#include "Utility/TrackingUtil.hpp"

#include "Engine/Engine.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Launch/Resources/Version.h"
#include "TimerManager.h"

#include <string>

AMixCastCamera::AMixCastCamera(const FObjectInitializer &ObjectInitializer)
{
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	cameraTransform = CreateDefaultSubobject<USceneComponent>(FName("Transform"));
	SetRootComponent(cameraTransform);

	fullRenderCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(FName("Background Cam"));
	fullRenderCamera->SetupAttachment(cameraTransform, NAME_None);
	fullRenderCamera->bCaptureEveryFrame = false;
	fullRenderCamera->bCaptureOnMovement = false;
	fullRenderCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	fullRenderCamera->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;

	foregroundCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(FName("Foreground"));
	foregroundCamera->SetupAttachment(cameraTransform, NAME_None);
	foregroundCamera->bCaptureEveryFrame = false;
	foregroundCamera->bCaptureOnMovement = false;
	foregroundCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	foregroundCamera->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;
	foregroundCamera->bEnableClipPlane = true;
	foregroundCamera->ShowFlags.SetFog(false);
	foregroundCamera->ShowFlags.SetAtmosphericFog(false);

	foregroundAlphaCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(FName("ForegroundAlpha"));
	foregroundAlphaCamera->SetupAttachment(cameraTransform, NAME_None);
	foregroundAlphaCamera->bCaptureEveryFrame = false;
	foregroundAlphaCamera->bCaptureOnMovement = false;
	foregroundAlphaCamera->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
	foregroundAlphaCamera->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;
	foregroundAlphaCamera->bEnableClipPlane = true;
	foregroundAlphaCamera->ShowFlags.SetFog(false);
	foregroundAlphaCamera->ShowFlags.SetAtmosphericFog(false);
}

void AMixCastCamera::BeginPlay()
{
	Super::BeginPlay();

	VirtualCamera* cameraData = SdkData::GetCameraById(Identifier);

	frameCanvas = UMixCastFrameCanvas::Create(this, cameraData->renderResolutionWidth, cameraData->renderResolutionHeight);
	float hFoV = MathUtil::VerticalFoVToHorizontal(cameraData->fieldOfView, (float)cameraData->renderResolutionWidth / cameraData->renderResolutionHeight);

	fullRenderCamera->FOVAngle = hFoV;
	fullRenderCamera->TextureTarget = frameCanvas->GetBackgroundTex();
	fullRenderCamera->CaptureScene();

	foregroundCamera->FOVAngle = hFoV;
	foregroundCamera->TextureTarget = frameCanvas->GetForegroundTex();
	foregroundCamera->CaptureScene();

	foregroundAlphaCamera->FOVAngle = hFoV;
	foregroundAlphaCamera->TextureTarget = frameCanvas->GetForegroundAlphaTex();
	foregroundAlphaCamera->PostProcessBlendWeight = 0;
	foregroundAlphaCamera->CaptureScene();

	AMixCastSdkActor::GetInstance()->GetServiceCommunicator()->ShareTexture(FString((Identifier + "_exp_layers").c_str()), frameCanvas);
}
void AMixCastCamera::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (fullRenderCamera) {
		if (fullRenderCamera->IsValidLowLevel()) {
			fullRenderCamera->TextureTarget = nullptr;
			fullRenderCamera->DestroyComponent();
		}
		fullRenderCamera = nullptr;
	}

	if (foregroundCamera) {
		if (foregroundCamera->IsValidLowLevel()) {
			foregroundCamera->TextureTarget = nullptr;
			foregroundCamera->DestroyComponent();
		}
		foregroundCamera = nullptr;
	}

	if (foregroundAlphaCamera) {
		if (foregroundAlphaCamera->IsValidLowLevel()) {
			foregroundAlphaCamera->TextureTarget = nullptr;
			foregroundAlphaCamera->DestroyComponent();
		}
		foregroundAlphaCamera = nullptr;
	}

	if (frameCanvas) {
		frameCanvas->ConditionalBeginDestroy();
		frameCanvas = nullptr;
	}

	Super::EndPlay(EndPlayReason);
}

void AMixCastCamera::CaptureFrame()
{
	UpdateTransform();
	UpdateCameraParameters();
	UpdateHiddenActors();

	TriggerSceneCaptures();
	TriggerFrameComposite();
}
void AMixCastCamera::UpdateTransform()
{
	FVector camPos;
	FQuat camRot;
	TrackingUtil::GetCameraPose(Identifier, camPos, camRot);
	RootComponent->SetRelativeLocationAndRotation(camPos, camRot);
	RootComponent->UpdateComponentToWorld();
}
void AMixCastCamera::UpdateCameraParameters()
{
	//Update foreground clipping plane
	float playerDist = CalculateForegroundDistance();	//meters
	FTransform camTrans = RootComponent->GetComponentTransform();
	FVector camForward = camTrans.TransformVector(FVector::ForwardVector);
	FVector clipPos = camTrans.TransformPosition(FVector::ForwardVector * playerDist);

	foregroundCamera->ClipPlaneBase = foregroundAlphaCamera->ClipPlaneBase = clipPos;
	foregroundCamera->ClipPlaneNormal = foregroundAlphaCamera->ClipPlaneNormal = -camForward;

	//Update post-processing settings
	APlayerController* vrPlayer = GEngine->GetFirstLocalPlayerController(GetWorld());
	AActor* camActor = vrPlayer && vrPlayer->PlayerCameraManager ?
		vrPlayer->PlayerCameraManager->ViewTarget.Target :
		nullptr;
	UCameraComponent* camComp = camActor ?
		Cast<UCameraComponent>(camActor->GetComponentByClass(UCameraComponent::StaticClass())) :
		nullptr;

	if (camComp)
	{
		fullRenderCamera->PostProcessSettings = foregroundCamera->PostProcessSettings = camComp->PostProcessSettings;
		fullRenderCamera->PostProcessBlendWeight = foregroundCamera->PostProcessBlendWeight = camComp->PostProcessBlendWeight;
	}
}
void AMixCastCamera::UpdateHiddenActors()
{
	TArray<AActor*>& hiddenActors = AMixCastSdkActor::GetInstance()->GetHiddenActors();

	fullRenderCamera->HiddenActors.Empty();
	foregroundCamera->HiddenActors.Empty();
	foregroundAlphaCamera->HiddenActors.Empty();

	for (int i = 0; i < hiddenActors.Num(); i++)
	{
		fullRenderCamera->HiddenActors.Add(hiddenActors[i]);
		foregroundCamera->HiddenActors.Add(hiddenActors[i]);
		foregroundAlphaCamera->HiddenActors.Add(hiddenActors[i]);
	}
}
void AMixCastCamera::TriggerSceneCaptures()
{
	fullRenderCamera->CaptureScene();
	foregroundCamera->CaptureScene();
	foregroundAlphaCamera->CaptureScene();
}
void AMixCastCamera::TriggerFrameComposite()
{
	frameCanvas->FastUpdateResource();
}

float AMixCastCamera::CalculateForegroundDistance()
{
	int hmdCount = 0;
	FVector devicePosSum = FVector::ZeroVector;
	for (int i = 0; i < SdkData::TrackedObjects.size(); i++)
	{
		TrackedObject* trackedObject = &SdkData::TrackedObjects[i];

		if (!trackedObject->connected || trackedObject->hideFromUser)
			continue;

		if (trackedObject->objectType != ObjectType::HMD)
			continue;

		FVector objectPosition = ThriftUtil::ThriftVectorToUnreal(trackedObject->position);

		//if (trackedObject->source == TrackingSource::OCULUS)
		//	objectPosition += trackedObject->rotation.unity * VRInfo.OCULUS_RIFT_HMD_TO_HEAD;
		//else if (trackedObject->source == TrackingSource::OPENVR)
		//	objectPosition += trackedObject->rotation.unity * VRInfo.VIVE_HMD_TO_HEAD;

		devicePosSum += objectPosition;
		hmdCount++;
	}

	if (hmdCount == 0)
		return 0;

	devicePosSum /= hmdCount;

	FVector cameraPos;
	FQuat cameraRot;
	TrackingUtil::GetCameraPose(Identifier, cameraPos, cameraRot);
	FTransform camTrans = FTransform(cameraRot, cameraPos);

	FVector playerPosInCameraSpace = camTrans.Inverse().TransformPosition(devicePosSum);
	return playerPosInCameraSpace.X;
}