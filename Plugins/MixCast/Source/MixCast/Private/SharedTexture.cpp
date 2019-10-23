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

#include "SharedTexture.h"

FSharedTexture FSharedTexture::FromRenderTarget(const UTextureRenderTarget2D& RenderTarget)
{
	if (!RenderTarget.IsValidLowLevel())
		return FSharedTexture();

	const FTextureRHIRef TextureRHI = RenderTarget.Resource->TextureRHI;

	if (TextureRHI == nullptr)
	{
		return {};
	}

	void* NativeResource = TextureRHI->GetNativeResource();

	// GetNativeResource returns a different type depending on the platform. 
	// For Windows, a DirectX 11 texture should be a safe bet.
	ID3D11Texture2D* D3D11Texture2D = static_cast<ID3D11Texture2D*>(NativeResource);
	const unsigned long Handle = GetHandle(*D3D11Texture2D);

	if (Handle == 0)
	{
		return {};
	}

	FSharedTexture SharedTexture;
	SharedTexture.Handle = Handle;
	SharedTexture.Format = GetFormat(*D3D11Texture2D);
	SharedTexture.Width = RenderTarget.SizeX;
	SharedTexture.Height = RenderTarget.SizeY;
	return SharedTexture;
}

unsigned long FSharedTexture::GetHandle(ID3D11Texture2D& D3D11Texture2D)
{
	IDXGIResource* DXGIResource;

	const HRESULT DXGIResourceResult = D3D11Texture2D.QueryInterface(
		__uuidof(IDXGIResource),
		reinterpret_cast<void**>(&DXGIResource)
	);

	if (FAILED(DXGIResourceResult))
	{
		return 0;
	}

	HANDLE SharedHandle;
	const HRESULT SharedHandleResult = DXGIResource->GetSharedHandle(&SharedHandle);
	DXGIResource->Release();

	if (FAILED(SharedHandleResult))
	{
		return 0;
	}

	return HandleToULong(SharedHandle);
}

int FSharedTexture::GetFormat(ID3D11Texture2D& D3D11Texture2D)
{
	D3D11_TEXTURE2D_DESC TextureDescription;
	D3D11Texture2D.GetDesc(&TextureDescription);
	return static_cast<int>(TextureDescription.Format);
}

