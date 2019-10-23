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

#include "MixCastData.generated.h"

// Holds the information stored in the registry. This is the main channel of
// communication between the Unity and Unreal version.
USTRUCT()
struct FGlobal
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY() int targetFramerate = 30;
	UPROPERTY() int spareRendersPerFrame = 1;
	UPROPERTY()	FString rootOutputPath = "";
};

USTRUCT()
struct FSensorPose
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY() FVector position;
	UPROPERTY() FQuat rotation;
};

USTRUCT()
struct FSceneDisplayData
{
	GENERATED_USTRUCT_BODY()

	enum PlacementMode
	{
		Camera, World, Headset
	};
	UPROPERTY() int mode = Camera;
	UPROPERTY() FVector position;
	UPROPERTY() FQuat rotation;
	UPROPERTY() float scale = 1.0f;
	UPROPERTY() float alpha = 1.0f;
};

USTRUCT()
struct FLightingData
{
	GENERATED_USTRUCT_BODY()

	// Toogle to easily turn on/off ligting while preserving set values
	UPROPERTY() bool isEnabled;
	// Factor lerps from no lighting (0) to full lighting (1)
	UPROPERTY() float effectAmount = 0;
	// Adds a constant value to lighting to set a baseline amount of light
	UPROPERTY() float baseLighting = 0.5f;
	// Multiplies the final lighting power
	UPROPERTY() float powerMultiplier = 1;
};

USTRUCT()
struct FCameraCalibrationData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY() FString id;

	// Camera parameters
	UPROPERTY() FString displayName;
	UPROPERTY() float deviceFoV;


	// Placement data
	UPROPERTY() FVector worldPosition = FVector(0, 0, 0);
	UPROPERTY() FQuat worldRotation = FQuat(0, 0, 0, 1);

	UPROPERTY() bool wasTracked;
	UPROPERTY() FString trackedByDevice;
	UPROPERTY() FString trackedByDeviceId;
	UPROPERTY() FVector trackedPosition;
	UPROPERTY() FQuat trackedRotation;

	// Motion data
	UPROPERTY() float positionSmoothTime;
	UPROPERTY() float rotationSmoothTime;

	// Output data
	UPROPERTY() int outputWidth;
	UPROPERTY() int outputHeight;

	//InScene display data
	UPROPERTY() FSceneDisplayData displayData;
	UPROPERTY() FLightingData lightingData;
};

USTRUCT()
struct FMixCastData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY() FGlobal global;
	UPROPERTY() TArray<FCameraCalibrationData> cameras;
	UPROPERTY() FString sourceVersion;

	UPROPERTY() FSensorPose sensorPose;
	UPROPERTY() int sensorIndex;

	int MajorVersion;
	int MinorVersion;
	int PatchVersion;
};
