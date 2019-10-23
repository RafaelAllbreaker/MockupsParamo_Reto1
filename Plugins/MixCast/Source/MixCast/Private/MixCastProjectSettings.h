// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MixCastProjectSettings.generated.h"

UCLASS(config = Game, defaultconfig)
class MIXCAST_API UMixCastProjectSettings : public UObject
{
	GENERATED_BODY()
public:
	UMixCastProjectSettings(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, config, Category = "Editor/Build")
	bool bRequireCommandLineFlag;
};
