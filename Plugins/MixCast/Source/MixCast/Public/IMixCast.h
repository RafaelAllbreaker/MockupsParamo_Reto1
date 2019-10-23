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
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

#define MIXCAST_SDK_MAJOR_VERSION 2
#define MIXCAST_SDK_MINOR_VERSION 0
#define MIXCAST_SDK_PATCH_VERSION 0

class FServiceSDKHandler;

class IMixCast : public IModuleInterface
{
public:
	static inline IMixCast& Get()
	{
		return FModuleManager::LoadModuleChecked< IMixCast >( "MixCast" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "MixCast" );
	}

	virtual bool IsActive() = 0;

	virtual bool SendExperienceEvent(const FString& EventId) = 0;

	DECLARE_EVENT_OneParam(FServiceSDKHandler, FReceivedCommandEvent, FString)
	virtual FReceivedCommandEvent& OnCommandReceived() = 0;
};

