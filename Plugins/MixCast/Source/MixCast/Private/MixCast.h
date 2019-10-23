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

#include "IMixCast.h"

#include "MixCastData.h"
#include "MixCastProjectSettings.h"
#include "MixCastLog.h"
#include "MixCastSdkAnalytics.h"
#include "ServiceSDKHandler.h"
#include "Utility/ThriftUtil.hpp"

#include "CoreMinimal.h"
#include "CoreGlobals.h"
#include "JsonObjectConverter.h"
#include "Misc/ConfigCacheIni.h"
#include "Modules/ModuleManager.h"

class MIXCAST_API FMixCast : public IMixCast
{
public:
	FMixCast();

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void ValidateExternalProjectSettings();

	virtual bool IsActive() { return bActive; }
	void SetActive(bool active);
	DECLARE_EVENT(IMixCast, FActivationEvent)
	FActivationEvent& OnActiveChanged() { return ActiveChanged; }

	bool SendExperienceEvent(const FString& EventId);
	FReceivedCommandEvent& OnCommandReceived() { return CommandReceived; }
protected:
	FDelegateHandle ConfigReadyDelegate;

	UPROPERTY() bool bActive;

	FActivationEvent ActiveChanged;
	FReceivedCommandEvent CommandReceived;

#if UE_EDITOR
	void RegisterSdkProjectSettings();
	void UnregisterSdkProjectSettings();
#endif
};