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

#include <string>

#include "Misc/App.h"
#include "Misc/ConfigCacheIni.h"
#include "Runtime/Launch/Resources/Version.h"
#include <libloaderapi.h>

#include "MixCast/Public/IMixCast.h"

const FString SDK_VERSION = FString::Printf(TEXT("%d.%d.%d"), MIXCAST_SDK_MAJOR_VERSION, MIXCAST_SDK_MINOR_VERSION, MIXCAST_SDK_PATCH_VERSION);
const FString UNREAL_VERSION = FString::Printf(TEXT("%d.%d.%d"), ENGINE_MAJOR_VERSION, ENGINE_MINOR_VERSION, ENGINE_PATCH_VERSION);

class MIXCAST_API MiscUtil
{
public:
	static FString GetCompanyName()
	{
		FString CompanyName;
		GConfig->GetString(TEXT("/Script/EngineSettings.GeneralProjectSettings"), TEXT("CompanyName"), CompanyName, GGameIni);

		if (CompanyName.Len() == 0)
		{
			CompanyName = FString(TEXT("DefaultCompany"));
		}

		return CompanyName;
	}

	static FString GetDeviceId()
	{
		FString DeviceId = FPlatformMisc::GetDeviceId();

		// The device ID uses the MAC address, which is not guaranteed to be supported on all platforms.
		if (DeviceId.Len() == 0)
		{
			DeviceId = FString(TEXT("NoDeviceId"));
		}

		return DeviceId;
	}

	static FString GetExecutablePath()
	{
		if (FApp::IsGame()) {
			TCHAR ExecutablePath[MAX_PATH];
			GetModuleFileName(nullptr, ExecutablePath, MAX_PATH);
			return FString(ExecutablePath);
		}
		else
		{
			return FPaths::Combine(FPlatformProcess::BaseDir(), FPlatformProcess::ExecutableName(false));
		}
	}

	static FString GetProjectName()
	{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 18
		return FString(FApp::GetProjectName());
#else
		return FString(FApp::GetGameName());
#endif
	}

	static std::string ToStdString(const FString& String)
	{
		return std::string(TCHAR_TO_UTF8(*String));
	}
};
