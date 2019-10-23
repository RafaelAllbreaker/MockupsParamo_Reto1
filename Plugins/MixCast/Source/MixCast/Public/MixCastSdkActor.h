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
#include "Engine/EngineTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "GameFramework/Actor.h"

#include "MixCast.h"
#include "ServiceCommunicator.h"
#include "TrackingOriginComponent.h"
#include "MixCastCameraGroup.h"

#include "MixCastSdkActor.generated.h"

/**
 * The Core MixCast SDK Actor
 */
UCLASS(HideCategories = ("Actor", "LOD", "HLOD", "Input", "Rendering", "Cooking", "Replication", "Collision"), meta = (DisplayName = "MixCast SDK Actor"))
class MIXCAST_API AMixCastSdkActor : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	static AMixCastSdkActor* GetInstance()
	{
		return Instance;
	}

	FServiceCommunicator* GetServiceCommunicator()
	{
		return ServiceCommunicator;
	}
	TArray<AActor*>& GetHiddenActors()
	{
		return hiddenActors;
	}
protected:
	static AMixCastSdkActor* Instance;

	FMixCast* mod;

	FServiceCommunicator* ServiceCommunicator = nullptr;
	UPROPERTY()
	UTrackingOriginComponent* TrackingOrigin = nullptr;
	UPROPERTY()
	UMixCastCameraGroup* CameraGroup = nullptr;
	UPROPERTY()
	TArray<AActor*> hiddenActors;

	FDelegateHandle ActiveChangedDelegate;
	FDelegateHandle CommandReceivedDelegate;

	void HandleActiveChanged();
	void HandleCommandReceived(FString commandStr);

	UFUNCTION(BlueprintNativeEvent, Category = "MixCast")
	void OnCommandReceived(const FString& commandStr);

	void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason) override;
	void Tick(float DeltaSeconds) override;
};


