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

#include "MixCast.h"
#include "MixCastSdkActor.h"
#include "SdkData.h"
#include "MixCastProjectSettings.h"

#include "Runtime/Launch/Resources/Version.h"
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 20
#include "Core/Public/Misc/CoreDelegates.h"
#else
#include "CoreDelegates.h"
#endif
#if UE_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"
#endif

IMPLEMENT_MODULE(FMixCast, MixCast)

#define LOCTEXT_NAMESPACE "MixCast"

FMixCast::FMixCast()
{
	bActive = false;
	ValidateExternalProjectSettings();
}

void FMixCast::StartupModule()
{
#if UE_EDITOR
	RegisterSdkProjectSettings();
#endif
	mixcast::thrift::ThriftUtil::SetUpLogCallback();
	MixCastSdkAnalytics::ReportAnalytics();
}

void FMixCast::ShutdownModule()
{
	if (IsActive())
		SetActive(false);
#if UE_EDITOR
	UnregisterSdkProjectSettings();
#endif
}

void FMixCast::SetActive(bool active)
{
	if (bActive == active)
		return;

	bActive = active;
	if (bActive)
	{
		ValidateExternalProjectSettings();
	}
	ActiveChanged.Broadcast();
}

bool FMixCast::SendExperienceEvent(const FString& EventId)
{
	if (bActive)
	{
		return AMixCastSdkActor::GetInstance()->GetServiceCommunicator()->SendExperienceEvent(EventId);
	}
	return false;
}

void FMixCast::ValidateExternalProjectSettings()
{
	if (GConfig->IsReadyForUse())
	{
		static const IConsoleVariable* CVarClipPlane = IConsoleManager::Get().FindConsoleVariable(TEXT("r.AllowGlobalClipPlane"));

		bool bAllowGlobalClipPlane = CVarClipPlane && CVarClipPlane->GetInt() == 1;

		if (!bAllowGlobalClipPlane)
		{
			UE_LOG(LogMixCastSDK, Error, TEXT("'Support global clip plane for Planar Reflections' option must be enabled in Project settings for MixCast to work correctly"));
		}

		if (ConfigReadyDelegate.IsValid())
		{
			FCoreDelegates::ConfigReadyForUse.Remove(ConfigReadyDelegate);
			ConfigReadyDelegate.Reset();
		}
	}
	else
	{
		if( !ConfigReadyDelegate.IsValid() )
			ConfigReadyDelegate = FCoreDelegates::ConfigReadyForUse.AddRaw(this, &FMixCast::ValidateExternalProjectSettings);
	}
}

#if UE_EDITOR
void FMixCast::RegisterSdkProjectSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "MixCast",
			LOCTEXT("RuntimeGeneralSettingsName", "MixCast"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Project configuration for the MixCast SDK"),
			GetMutableDefault<UMixCastProjectSettings>()
		);
	}
}
void FMixCast::UnregisterSdkProjectSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "MixCast");
	}
}
#endif

#undef LOCTEXT_NAMESPACE