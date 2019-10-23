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

#include "MixCastData.h"
#include "MixCastFrameCanvas.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/SceneCapture2D.h"
#include "TimerManager.h"

#include <string>

#include "MixCastCamera.generated.h"

UCLASS(HideCategories = ("Actor", "HLOD", "Input"))
class MIXCAST_API AMixCastCamera : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	std::string Identifier;

	void CaptureFrame();
protected:
	UPROPERTY()
		USceneComponent* cameraTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* fullRenderCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* foregroundCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneCaptureComponent2D* foregroundAlphaCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMixCastFrameCanvas* frameCanvas;


	void BeginPlay() override;
	void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	void UpdateTransform();
	void UpdateCameraParameters();
	void UpdateHiddenActors();

	void TriggerSceneCaptures();
	void TriggerFrameComposite();

	float CalculateForegroundDistance();
private:

};
