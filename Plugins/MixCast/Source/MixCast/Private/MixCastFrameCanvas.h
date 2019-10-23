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
#include "Engine/CanvasRenderTarget2D.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "MixCastFrameCanvas.generated.h"

UCLASS()
class MIXCAST_API UMixCastFrameCanvas : public UCanvasRenderTarget2D
{
	GENERATED_UCLASS_BODY()

public:
	static UMixCastFrameCanvas* Create(UObject* WorldContextObject, int layerWidth, int layerHeight);

	UMixCastFrameCanvas();
	~UMixCastFrameCanvas();

	UTextureRenderTarget2D* GetBackgroundTex() { return fullRenderTex; }
	UTextureRenderTarget2D* GetForegroundTex() { return foregroundTex; }
	UTextureRenderTarget2D* GetForegroundAlphaTex() { return foregroundAlphaTex; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* fullRenderTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* foregroundTex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextureRenderTarget2D* foregroundAlphaTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInstanceDynamic* fullRenderBlitMat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInstanceDynamic* foregroundBlitMat;

	UFUNCTION()
	void BlitLayers(UCanvas* Canvas, int32 Width, int32 Height);

	void Initialize(int width, int height);
	UTextureRenderTarget2D* CreateRenderTarget(int width, int height);
};