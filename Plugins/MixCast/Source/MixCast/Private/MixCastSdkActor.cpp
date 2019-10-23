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

#include "MixCastSdkActor.h"
#include "MixCast.h"
#include "SdkData.h"
#include "MixCastLog.h"
#include "Utility/CommandLineUtil.hpp"

#include "Async/Async.h"
#include "Engine/Engine.h"
#include "HeadMountedDisplay.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
#include "IXRTrackingSystem.h"
#else
#include "IHeadMountedDisplay.h"
#endif

AMixCastSdkActor* AMixCastSdkActor::Instance;

AMixCastSdkActor::AMixCastSdkActor( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PostUpdateWork;
	PrimaryActorTick.bStartWithTickEnabled = true;

	Instance = this;
}

void AMixCastSdkActor::BeginPlay()
{
	Super::BeginPlay();

	mod = (FMixCast*)&IMixCast::Get();

#if !UE_EDITOR
	if (SdkData::GetProjectSettings()->bRequireCommandLineFlag && !CommandLineUtil::IncludesMixCastFlag())
	{
		mod = nullptr;	//signal we didn't initialize
		Destroy();
		return;
	}
#endif

#if UE_EDITOR
	mod->ValidateExternalProjectSettings();	//Give developers early notice of incorrect settings during testing
#endif

	TrackingOrigin = NewObject<UTrackingOriginComponent>(this);
	TrackingOrigin->Rename(TEXT("Tracking Origin"));
	TrackingOrigin->bWantsBeginPlay = true;
	if (TrackingOrigin)
	{
		TrackingOrigin->RegisterComponent();
		TrackingOrigin->AttachTo(GetRootComponent(), NAME_None);	//this becomes the root component
	}

	CameraGroup = NewObject<UMixCastCameraGroup>(this);
	CameraGroup->Rename(TEXT("Cameras"));
	CameraGroup->bWantsBeginPlay = true;
	if (CameraGroup)
	{
		CameraGroup->RegisterComponent();
		CameraGroup->AttachTo(TrackingOrigin, NAME_None);
	}

	ActiveChangedDelegate = mod->OnActiveChanged().AddUObject(this, &AMixCastSdkActor::HandleActiveChanged);
	CommandReceivedDelegate = mod->OnCommandReceived().AddUObject(this, &AMixCastSdkActor::HandleCommandReceived);

	ServiceCommunicator = new FServiceCommunicator();

	HandleActiveChanged();
}
void AMixCastSdkActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (mod == nullptr)
		return;

	mod->SetActive(false);
	mod->OnCommandReceived().Remove(CommandReceivedDelegate);
	mod->OnActiveChanged().Remove(ActiveChangedDelegate);

	CameraGroup->DestroyComponent();
	CameraGroup = nullptr;

	delete ServiceCommunicator;

	ServiceCommunicator = nullptr;

	Instance = nullptr;
}


void AMixCastSdkActor::HandleActiveChanged()
{
	if (!mod->IsActive())
	{
		CameraGroup->ClearSpawnedCameras();
	}
}

void AMixCastSdkActor::HandleCommandReceived(FString commandStr)
{
	OnCommandReceived(commandStr);
}
void AMixCastSdkActor::OnCommandReceived_Implementation(const FString& commandStr) { }

void AMixCastSdkActor::Tick(const float DeltaSeconds)
{
	if (!mod->IsActive() || SdkData::UserSettings.sourceVersion.Len() == 0)
		return;

	if (TrackingOrigin->IsTrackingOriginAvailable())
		TrackingOrigin->SetTransformToTrackingOrigin();

	CameraGroup->SynchronizeSpawnedCameras();
	CameraGroup->RenderCameras();
}