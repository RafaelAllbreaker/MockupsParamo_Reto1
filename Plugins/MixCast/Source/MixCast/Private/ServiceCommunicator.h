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

#include "Generated/SDK_Service.h"
#include "Generated/Service_SDK.h"
#include "Generated/SharedTextureCommunication.h"
#include "MixCast.h"
#include "ServiceSDKHandler.h"
#include "SharedTexture.h"
#include "ThriftClient.h"
#include "ThriftServer.h"

#include "Containers/Queue.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"

#include <memory>

using namespace mixcast::data;
using namespace mixcast::thrift;

// Manages RPC communication with other MixCast applications, namely Service and Capture.
class MIXCAST_API FServiceCommunicator : public FRunnable
{
public:
	FServiceCommunicator();
	~FServiceCommunicator();

	// FRunnable overrides:
	uint32 Run() override;
	void Stop() override;

	bool SendExperienceEvent(const FString& EventId) const;
	bool SetAutoSnapshot(bool bEnable, const FString& CameraId) const;
	bool SetVideoRecording(bool bEnable, const FString& CameraId) const;
	bool SetVideoStreaming(bool bEnable, const FString& CameraId) const;
	bool TakeSnapshot(const FString& CameraId) const;

	// Sends a DirectX texture handle.
	void ShareTexture(const FString& TextureId, const UTextureRenderTarget2D* RenderTarget);
private:
	typedef TPair<FString, const UTextureRenderTarget2D*> SharedTextureSource;

	FMixCast* mod;
	int missedPingCount;

	bool bRunThread = true;
	FDelegateHandle ActiveChangedDelegate;
	TThriftClient<SDK_ServiceClient> SDKServiceClient;
	std::shared_ptr<FServiceSDKHandler> ServiceSDKHandler;
	TThriftServer<Service_SDKProcessor, Service_SDKIf> ServiceSDKServer;
	TThriftClient<SharedTextureCommunicationClient> SharedTextureClient;

	TQueue<SharedTextureSource, EQueueMode::Spsc> SharedTextureQueue;
	int SharedTextureQueueSize = 0;

	FRunnableThread* Thread;

	void NotifySDKStarted() const;
	void NotifySDKStopped() const;
	void PingService();
	bool SendSharedTexture(const FString& TextureId, const UTextureRenderTarget2D* RenderTarget) const;
	void SendSharedTextures();

	void HandleActiveChanged();
};
