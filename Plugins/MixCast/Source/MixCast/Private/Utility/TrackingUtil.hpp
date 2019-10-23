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

#pragma once

#include <string>

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "IHeadMountedDisplay.h"
#include "Runtime/Launch/Resources/Version.h"

#include "MathUtil.hpp"
#include "ThriftUtil.hpp"
#include "SdkData.h"
#include "MixCastSdkActor.h"
#include "Generated/Math_types.h"
#include "Generated/TrackedObject_types.h"


#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
#include "IXRTrackingSystem.h"
#endif

class MIXCAST_API TrackingUtil
{
public:
	static void GetCameraPose(std::string cameraId, FVector& position, FQuat& rotation)
	{
		VirtualCamera* camData = SdkData::GetCameraById(cameraId);
		if (camData != nullptr)
		{
			position = ThriftUtil::ThriftVectorToUnreal(camData->currentPosition);
			rotation = ThriftUtil::ThriftQuatToUnreal(camData->currentRotation);
		}
	}

	static void CorrectWorldPose(int32 sensorId, FVector& pos, FQuat& rot)
	{
		const FMixCastData* MixCastData = &SdkData::UserSettings;

		const FVector oldSensorPos = MathUtil::UnityPositionToUnreal(MixCastData->sensorPose.position);
		const FQuat oldSensorRot = MathUtil::UnityRotationToUnreal(MixCastData->sensorPose.rotation);
		const FTransform oldSensorMat = FTransform(oldSensorRot, oldSensorPos);

		FVector newSensorPos;
		FQuat newSensorRot;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		GEngine->XRSystem->GetCurrentPose(sensorId, newSensorRot, newSensorPos);
#else
		float sensorFoVLeft, sensorFoVRight, sensorFoVTop, sensorFoVBottom, sensorCamDist, sensorNearPlane, sensorFarPlane;
		GEngine->HMDDevice->GetTrackingSensorProperties(sensorId, newSensorPos, newSensorRot, sensorFoVLeft, sensorFoVRight, sensorFoVTop, sensorFoVBottom, sensorCamDist, sensorNearPlane, sensorFarPlane);
#endif

		FVector newSensorForward = newSensorRot * FVector::ForwardVector;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		newSensorForward *= FVector(-1, -1, 0);
#else
		newSensorForward *= FVector(1, 1, 0);
#endif

		newSensorRot = newSensorForward.ToOrientationQuat();
		const FTransform newSensorMat = FTransform(newSensorRot, newSensorPos);

		const FTransform oldPoseMat = FTransform(rot, pos);
		const FTransform sensorSpacePoseMat = oldPoseMat * oldSensorMat.Inverse();
		const FTransform newPoseMat = sensorSpacePoseMat * newSensorMat;

		pos = newPoseMat.GetLocation();
		rot = newPoseMat.GetRotation();
	}

	static bool IsPlatformOculus()
	{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		FName sysName = GEngine->XRSystem->GetSystemName();
		return sysName.IsEqual(TEXT("OculusHMD"));
#else
		return GEngine->HMDDevice->GetHMDDeviceType() == EHMDDeviceType::DT_OculusRift;
#endif
	}

	static int32 GetReferenceSensorIndex()
	{
		const FMixCastData* MixCastData = &SdkData::UserSettings;

		FQuat refOrientation = MathUtil::UnityRotationToUnreal(MixCastData->sensorPose.rotation);

		int loopCount = 0;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		TArray<int32> sensorIndices;
		if (!GEngine->XRSystem->EnumerateTrackedDevices(sensorIndices, EXRTrackedDeviceType::TrackingReference))
			return -1;
		loopCount = sensorIndices.Num();
#else
		IHeadMountedDisplay* hmd = GEngine->HMDDevice.Get();
		if (hmd->IsHMDEnabled() && hmd->DoesSupportPositionalTracking())
			loopCount = hmd->GetNumOfTrackingSensors();
#endif
		if (loopCount == 0)
			return -1;

		int closestIndex = -1;
		float closestAngleDist = 180;
		for (int i = 0; i < loopCount; i++) {
			FVector sensorPos;
			FQuat sensorRot;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
			if (GEngine->XRSystem->GetCurrentPose(sensorIndices[i], sensorRot, sensorPos))
#else
			float sensorFoVLeft, sensorFoVRight, sensorFoVTop, sensorFoVBottom, sensorCamDist, sensorNearPlane, sensorFarPlane;
			if (hmd->GetTrackingSensorProperties(i, sensorPos, sensorRot, sensorFoVLeft, sensorFoVRight, sensorFoVTop, sensorFoVBottom, sensorCamDist, sensorNearPlane, sensorFarPlane))
#endif
			{
				FVector sensorForward = sensorRot * FVector::ForwardVector;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
				sensorForward *= FVector(-1, -1, 0);
#else
				sensorForward *= FVector(1, 1, 0);
#endif
				sensorForward.Normalize();
				sensorRot = sensorForward.ToOrientationQuat();

				float angle = FMath::RadiansToDegrees(sensorRot.AngularDistance(refOrientation));
				if (closestIndex == -1 || angle < closestAngleDist)
				{
					closestIndex = i;
					closestAngleDist = angle;
				}
			}
		}

#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		if (closestIndex != -1)
			return sensorIndices[closestIndex];
		return -1;
#else
		return closestIndex;
#endif
	}
protected:

};
