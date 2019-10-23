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

#include "MixCastCameraGroup.h"

#include "MixCast.h"
#include "SdkData.h"
#include "MixCastLog.h"
#include "SharedTexture.h"
#include "Utility/CameraUtil.hpp"

#include "Async/Async.h"

#include "Camera/CameraComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "HeadMountedDisplay.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Launch/Resources/Version.h"
#include "HeadMountedDisplay.h"

UMixCastCameraGroup::UMixCastCameraGroup(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMixCastCameraGroup::SynchronizeSpawnedCameras()
{
	for (int i = cameras.Num() - 1; i >= 0; i--)
	{
		bool foundAgain = false;
		for (int j = 0; j < SdkData::VirtualCameras.size() && !foundAgain; j++)
			foundAgain |= SdkData::VirtualCameras[j].identifier.compare(cameras[i]->Identifier) == 0;

		if (!foundAgain)
		{
			if (cameras[i]->IsValidLowLevel())
				cameras[i]->Destroy();
			cameras.RemoveAt(i);
		}
	}

	for (int i = 0; i < SdkData::VirtualCameras.size(); i++)
	{
		bool alreadyFound = false;
		for (int j = 0; j < cameras.Num() && !alreadyFound; j++)
			alreadyFound |= cameras[j]->Identifier.compare(SdkData::VirtualCameras[i].identifier) == 0;

		if (!alreadyFound)
		{
			AActor* camActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, AMixCastCamera::StaticClass(), FTransform::Identity);
			AMixCastCamera* cam = Cast<AMixCastCamera>(camActor);
			cam->Identifier = SdkData::VirtualCameras[i].identifier;
			cam->GetRootComponent()->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
			UGameplayStatics::FinishSpawningActor(camActor, FTransform::Identity);
			cameras.Add(cam);
		}
	}
}

void UMixCastCameraGroup::ClearSpawnedCameras()
{
	for (int i = 0; i < cameras.Num(); i++)
	{
		if (cameras[i]->IsValidLowLevel())
			cameras[i]->Destroy();
	}
	cameras.Empty();
}

void UMixCastCameraGroup::RenderCameras()
{
	if (cameras.Num() == 0)
		return;

	//render used cameras
	float curTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	if (curTime >= nextRenderTime) {
		for (auto camera : cameras)
		{
			if (CameraUtil::IsRunningInRealtime(camera->Identifier))
				camera->CaptureFrame();
		}

		if (nextRenderTime <= 0)
			nextRenderTime = curTime;
		while (nextRenderTime < curTime)
			nextRenderTime += 1.0f / SdkData::UserSettings.global.targetFramerate;
	}
}