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

#include "Engine/TextureRenderTarget2D.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include <d3d11.h>
#include "Windows/HideWindowsPlatformTypes.h"

// Simple container to hold information about a shared DirectX texture.
struct MIXCAST_API FSharedTexture
{
	unsigned long Handle = 0;
	int Format = 0;
	int Width = 0;
	int Height = 0;

	// Whether the handle is a valid texture pointer.
	bool IsValid() const
	{
		return Handle != 0;
	}

	static FSharedTexture FromRenderTarget(const UTextureRenderTarget2D& RenderTarget);

private:
	static unsigned long GetHandle(ID3D11Texture2D& D3D11Texture2D);
	static int GetFormat(ID3D11Texture2D& D3D11Texture2D);
};
