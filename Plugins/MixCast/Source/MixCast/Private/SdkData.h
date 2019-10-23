// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Generated/Service_SDK_types.h"
#include "MixCastData.h"
#include "MixCastProjectSettings.h"

#include <memory>

using namespace mixcast::data;
using namespace mixcast::thrift;

class MIXCAST_API SdkData
{
public:
	static FMixCastData UserSettings;

	static std::vector<TrackedObject> TrackedObjects;
	static std::vector<VirtualCamera> VirtualCameras;
	static std::vector<Viewfinder> Viewfinders;
	static Desktop Desktop;

	static const UMixCastProjectSettings* GetProjectSettings() { return GetDefault<UMixCastProjectSettings>(); }

	static TrackedObject* GetTrackedObjectById(std::string id)
	{
		for (int i = 0; i < TrackedObjects.size(); i++)
			if (TrackedObjects[i].identifier.compare(id) == 0)
				return &TrackedObjects[i];
		return nullptr;
	}
	static VirtualCamera* GetCameraById(std::string id)
	{
		for (int i = 0; i < VirtualCameras.size(); i++)
			if (VirtualCameras[i].identifier.compare(id) == 0)
				return &VirtualCameras[i];
		return nullptr;
	}
};

FMixCastData SdkData::UserSettings;
std::vector<TrackedObject> SdkData::TrackedObjects;
std::vector<VirtualCamera> SdkData::VirtualCameras;
std::vector<Viewfinder> SdkData::Viewfinders;
Desktop SdkData::Desktop;