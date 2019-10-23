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

#include "ServiceSDKHandler.h"

#include "MixCast.h"
#include "SdkData.h"
#include "MixCastLog.h"
#include "thrift/transport/TPipe.h"

#include "Async/Async.h"
#include "Engine/Engine.h"

void FServiceSDKHandler::SetActivationState(const bool active)
{
	AsyncTask(ENamedThreads::GameThread, [&]()
	{
		if (!GEngine)
			return;

		if (IMixCast::IsAvailable())
			((FMixCast*)&IMixCast::Get())->SetActive(active);
	});
}

void FServiceSDKHandler::NotifyServiceStarted()
{
	ServiceStartedEvent.Broadcast();
}

void FServiceSDKHandler::SendLegacyData(const std::string& dataJson)
{
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		FJsonObjectConverter::JsonObjectStringToUStruct<FMixCastData>(FString(dataJson.c_str()), &SdkData::UserSettings, 0, 0);
	});
}

void FServiceSDKHandler::UpdateTrackedObjectMetadata(const std::vector<TrackedObject>& trackedObjects)
{
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		SdkData::TrackedObjects.clear();
		for (int i = 0; i < trackedObjects.size(); i++)
			SdkData::TrackedObjects.push_back(trackedObjects[i]);
	});
}

void FServiceSDKHandler::UpdateCameraMetadata(const std::vector<VirtualCamera>& cameras)
{
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		SdkData::VirtualCameras.clear();
		for (int i = 0; i < cameras.size(); i++)
			SdkData::VirtualCameras.push_back(cameras[i]);
	});
}

void FServiceSDKHandler::UpdateViewfinderMetadata(const std::vector<Viewfinder>& viewfinders)
{
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		SdkData::Viewfinders.clear();
		for (int i = 0; i < viewfinders.size(); i++)
			SdkData::Viewfinders.push_back(viewfinders[i]);
	});
}

void FServiceSDKHandler::UpdateDesktopMetadata(const Desktop& desktop)
{
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		SdkData::Desktop = desktop;
	});
}

void FServiceSDKHandler::NotifyExternalTexturesUpdated(const std::vector<SharedTexPacket>& textureInfo)
{
	//MIXCAST_LOG("TODO: implement NotifyExternalTexturesUpdated");
}

void FServiceSDKHandler::ResetWorldOrientation()
{
	MIXCAST_LOG("TODO: implement ResetWorldOrentiation");
}

void FServiceSDKHandler::ModifyWorldOrientation(const double degrees)
{
	MIXCAST_LOG("TODO: implement ModifyWorldOrientation");
}

void FServiceSDKHandler::SendExperienceCommand(const std::string& cmdId)
{
	FString fStr(cmdId.c_str());
	MIXCAST_LOG("SendExperienceCommand(%s)", *fStr);
	AsyncTask(ENamedThreads::GameThread, [=]()
	{
		IMixCast* mod = &IMixCast::Get();
		if (mod->IsActive())
			mod->OnCommandReceived().Broadcast(fStr);
	});
}


void FServiceSDKHandler::validate_function_list(std::vector<std::string>& _return)
{
	const int FUNC_COUNT = 13;
	const std::string FunctionList[FUNC_COUNT] = {
		"SetActivationState",
		"NotifyServiceStarted",

		"SendLegacyData",

		"UpdateTrackedObjectMetadata",
		"UpdateCameraMetadata",
		"UpdateViewfinderMetadata",
		"UpdateDesktopMetadata",

		"NotifyExternalTexturesUpdated",

		"ResetWorldOrientation",
		"ModifyWorldOrientation",

		"SendExperienceCommand",

		"validate_function_list",
		"validate_ping",
	};
	for (int i = 0; i < FUNC_COUNT; i++)
		_return.push_back(FunctionList[i]);
}

void FServiceSDKHandler::validate_ping()
{
	// Do nothing.
}
