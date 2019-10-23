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

#include "TrackingOriginComponent.h"

#include "MixCast.h"
#include "MixCastData.h"
#include "MixCastLog.h"
#include "Utility/TrackingUtil.hpp"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "IHeadMountedDisplay.h"
#include "Runtime/Launch/Resources/Version.h"

#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
#include "IXRTrackingSystem.h"
#endif

UTrackingOriginComponent::UTrackingOriginComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UTrackingOriginComponent::IsTrackingOriginAvailable()
{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
	return GEngine->XRSystem.IsValid() &&
		GEngine->XRSystem->DoesSupportPositionalTracking() &&
		GEngine->XRSystem->GetHMDDevice() &&
		GEngine->XRSystem->GetHMDDevice()->IsHMDConnected() &&
		GEngine->XRSystem->GetStereoRenderingDevice().IsValid() &&
		GEngine->XRSystem->GetStereoRenderingDevice()->IsStereoEnabled() &&
		GEngine->XRSystem->IsTracking(IXRTrackingSystem::HMDDeviceId);
#else
	return GEngine->HMDDevice.IsValid() &&
		GEngine->HMDDevice->IsHMDConnected() &&
		GEngine->HMDDevice->IsHMDEnabled() &&
		GEngine->HMDDevice->DoesSupportPositionalTracking() &&
		GEngine->HMDDevice->HasValidTrackingPosition();
#endif
}

void UTrackingOriginComponent::SetTransformToTrackingOrigin()
{
	FTransform engineTrackingToWorld = GetEngineTrackingToWorldTransform();
	FVector originPos = engineTrackingToWorld.GetLocation();
	FQuat originRot = engineTrackingToWorld.GetRotation();

	if (TrackingUtil::IsPlatformOculus())
	{
		int32 referenceSensorIndex = TrackingUtil::GetReferenceSensorIndex();
		if (referenceSensorIndex != -1)
		{
			FVector spaceOffsetPos = FVector::ZeroVector;
			FQuat spaceOffsetRot = FQuat::Identity;
			TrackingUtil::CorrectWorldPose(referenceSensorIndex, spaceOffsetPos, spaceOffsetRot);
			originPos += originRot * spaceOffsetPos;
			originRot *= spaceOffsetRot;
		}
	}

	SetWorldTransform(FTransform(originRot, originPos));
}
FTransform UTrackingOriginComponent::GetEngineTrackingToWorldTransform()
{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 20
	TSharedPtr<IXRTrackingSystem, ESPMode::ThreadSafe> xrSystem = GEngine->XRSystem;

	if (xrSystem->HasValidTrackingPosition())
	{
		FTransform originTransform = xrSystem->GetTrackingToWorldTransform();

		if (!TrackingUtil::IsPlatformOculus() && xrSystem->GetTrackingOrigin() == EHMDTrackingOrigin::Eye)
		{
			FTransform floorToEye;
			if (xrSystem->GetFloorToEyeTrackingTransform(floorToEye))
				originTransform = floorToEye * originTransform;
		}

		return originTransform;
	}
	return FTransform();
#elif ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 19
	TSharedPtr<IXRTrackingSystem, ESPMode::ThreadSafe> xrSystem = GEngine->XRSystem;

	if (xrSystem->HasValidTrackingPosition())
	{
		return xrSystem->GetTrackingToWorldTransform();
	}
	return FTransform();
#elif ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
	UWorld* curWorld = GetWorld();

	FQuat trackedHmdRot;
	FVector trackedHmdPos;
	if (curWorld && GEngine->XRSystem->GetCurrentPose(IXRTrackingSystem::HMDDeviceId, trackedHmdRot, trackedHmdPos))
	{
		APlayerController* localPlayerController = GEngine->GetFirstLocalPlayerController(curWorld);
		if (localPlayerController) {
			APlayerCameraManager* playerCamManager = localPlayerController->PlayerCameraManager;

			FVector worldHmdPos = playerCamManager->GetCameraLocation();
			FRotator worldHmdRot = playerCamManager->GetCameraRotation();

			FQuat worldRoomRot = worldHmdRot.Quaternion() * trackedHmdRot.Inverse();
			FVector worldRoomPos = worldHmdPos - worldRoomRot * trackedHmdPos;

			return FTransform(worldRoomRot, worldRoomPos);
		}
	}
	return FTransform::Identity;
#else
	UWorld* curWorld = GetWorld();
	if (curWorld && GEngine->HMDDevice->HasValidTrackingPosition())
	{
		FQuat trackedHmdRot;
		FVector trackedHmdPos;
		GEngine->HMDDevice->GetCurrentOrientationAndPosition(trackedHmdRot, trackedHmdPos);

		APlayerController* localPlayerController = GEngine->GetFirstLocalPlayerController(curWorld);
		if (localPlayerController) {
			APlayerCameraManager* playerCamManager = localPlayerController->PlayerCameraManager;

			FVector worldHmdPos = playerCamManager->GetCameraLocation();
			FRotator worldHmdRot = playerCamManager->GetCameraRotation();

			FQuat worldRoomRot = worldHmdRot.Quaternion() * trackedHmdRot.Inverse();
			FVector worldRoomPos = worldHmdPos - worldRoomRot * trackedHmdPos;

			return FTransform(worldRoomRot, worldRoomPos);
		}

		return FTransform(trackedHmdRot, trackedHmdPos);
	}
	return FTransform::Identity;
#endif
}
