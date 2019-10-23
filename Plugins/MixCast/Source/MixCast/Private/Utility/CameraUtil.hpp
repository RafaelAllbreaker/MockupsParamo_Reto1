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

#include "CoreMinimal.h"

#include "SdkData.h"

class MIXCAST_API CameraUtil
{
public:
	static bool IsRunningInRealtime(std::string cameraId)
	{
		return IsBeingDisplayedOnDesktop(cameraId) || IsVideoRecording(cameraId) || IsVideoStreaming(cameraId);
	}
	static bool IsBeingDisplayedOnDesktop(std::string cameraId)
	{
		for (int i = 0; i < SdkData::Desktop.displayingCameraIds.size(); i++)
			if (cameraId.compare(SdkData::Desktop.displayingCameraIds[i]) == 0)
				return true;
		return false;
	}
	static bool IsVideoRecording(std::string cameraId)
	{
		VirtualCamera* camData = SdkData::GetCameraById(cameraId);
		if (camData != nullptr)
			return camData->videoRecordingEnabled;
		return false;
	}
	static bool IsVideoStreaming(std::string cameraId)
	{
		VirtualCamera* camData = SdkData::GetCameraById(cameraId);
		if (camData != nullptr)
			return camData->videoStreamingEnabled;
		return false;
	}
};
