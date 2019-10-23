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

#include "MixCastFrameCanvas.h"

#include "Engine/Canvas.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Launch/Resources/Version.h"

UMixCastFrameCanvas* UMixCastFrameCanvas::Create(UObject* WorldContextObject, int layerWidth, int layerHeight)
{
	UMixCastFrameCanvas* obj = NewObject<UMixCastFrameCanvas>(WorldContextObject);
	obj->Initialize(layerWidth, layerHeight);
	return obj;
}

UMixCastFrameCanvas::UMixCastFrameCanvas(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 22
	bNeedsTwoCopies = true;
#endif

	static ConstructorHelpers::FObjectFinder<UMaterial> Find_FullRenderBlitMat(TEXT("Material'/MixCast/FullRenderBlit.FullRenderBlit'"));
	if (Find_FullRenderBlitMat.Succeeded())
	{
		fullRenderBlitMat = UMaterialInstanceDynamic::Create(
			Cast<UMaterialInterface>(Find_FullRenderBlitMat.Object),
			this,
			TEXT("FullRenderBlit")
		);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> Find_ForegroundBlitMat(TEXT("Material'/MixCast/ForegroundBlit.ForegroundBlit'"));
	if (Find_ForegroundBlitMat.Succeeded())
	{
		foregroundBlitMat = UMaterialInstanceDynamic::Create(
			Cast<UMaterialInterface>(Find_ForegroundBlitMat.Object),
			this,
			TEXT("ForegroundBlit")
		);
	}

	OnCanvasRenderTargetUpdate.AddUniqueDynamic(this, &UMixCastFrameCanvas::BlitLayers);
}
void UMixCastFrameCanvas::Initialize(int layerWidth, int layerHeight)
{
	bAutoGenerateMips = false;
	SRGB = 0;
	bGPUSharedFlag = true;
	InitCustomFormat(layerWidth, layerHeight * 2, PF_B8G8R8A8, false);
	UpdateResourceImmediate();

	fullRenderTex = CreateRenderTarget(layerWidth, layerHeight);
	foregroundTex = CreateRenderTarget(layerWidth, layerHeight);
	foregroundAlphaTex = CreateRenderTarget(layerWidth, layerHeight);

	fullRenderBlitMat->SetTextureParameterValue(TEXT("FullRenderTex"), fullRenderTex);

	foregroundBlitMat->SetTextureParameterValue(TEXT("ForegroundTex"), foregroundTex);
	foregroundBlitMat->SetTextureParameterValue(TEXT("ForegroundAlphaTex"), foregroundAlphaTex);
}

UMixCastFrameCanvas::~UMixCastFrameCanvas()
{
	if (fullRenderTex) {
		if (fullRenderTex->IsValidLowLevel())
			fullRenderTex->ConditionalBeginDestroy();
		fullRenderTex = nullptr;
	}
	if (foregroundTex) {
		if (foregroundTex->IsValidLowLevel())
			foregroundTex->ConditionalBeginDestroy();
		foregroundTex = nullptr;
	}
	if (foregroundAlphaTex) {
		if (foregroundAlphaTex->IsValidLowLevel())
			foregroundAlphaTex->ConditionalBeginDestroy();
		foregroundAlphaTex = nullptr;
	}
}

void UMixCastFrameCanvas::BlitLayers(UCanvas* Canvas, int32 Width, int32 Height)
{
	FVector2D layerSize = FVector2D{ (float)Width,  0.5f * Height };

	Canvas->K2_DrawMaterial(
		fullRenderBlitMat,
		FVector2D::ZeroVector,
		layerSize,
		FVector2D::ZeroVector
	);
	Canvas->K2_DrawMaterial(
		foregroundBlitMat,
		FVector2D{ 0, layerSize.Y },
		layerSize,
		FVector2D::ZeroVector
	);
}

UTextureRenderTarget2D* UMixCastFrameCanvas::CreateRenderTarget(int width, int height)
{
	UTextureRenderTarget2D* tex = NewObject<UTextureRenderTarget2D>(this);
	tex->bAutoGenerateMips = false;
	tex->SRGB = 0;
	tex->InitCustomFormat(width, height, PF_B8G8R8A8, false);
	tex->UpdateResourceImmediate();
	return tex;
}