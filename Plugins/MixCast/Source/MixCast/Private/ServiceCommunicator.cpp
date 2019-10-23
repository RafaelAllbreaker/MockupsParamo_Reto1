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

#include "ServiceCommunicator.h"

#include "Utility/MiscUtil.hpp"

#define THREAD_UPDATE_FREQUENCY (1.0f / 3.0f) // seconds

FServiceCommunicator::FServiceCommunicator()
	: SDKServiceClient("SDK_SERVICE")
	, ServiceSDKHandler(std::make_shared<FServiceSDKHandler>())
	, ServiceSDKServer("SERVICE_SDK", ServiceSDKHandler)
	, SharedTextureClient("SHAREDTEXTURECOMMUNICATION")
{
	mod = (FMixCast*)&IMixCast::Get();

	ServiceSDKHandler->OnServiceStarted().AddRaw(this, &FServiceCommunicator::NotifySDKStarted);

	Thread = FRunnableThread::Create(this, TEXT("FServiceCommunicator"), 0, TPri_BelowNormal);
}

FServiceCommunicator::~FServiceCommunicator()
{
	delete Thread;
	Thread = nullptr;
}

uint32 FServiceCommunicator::Run()
{
	NotifySDKStarted();

	ActiveChangedDelegate = mod->OnActiveChanged().AddRaw(this, &FServiceCommunicator::HandleActiveChanged);

	while (bRunThread)
	{
		if (mod->IsActive()) {
			PingService();
			SendSharedTextures();
		}
		FPlatformProcess::Sleep(THREAD_UPDATE_FREQUENCY);
	}

	NotifySDKStopped();

	return 0;
}

void FServiceCommunicator::Stop()
{
	((FMixCast*)&IMixCast::Get())->OnActiveChanged().Remove(ActiveChangedDelegate);
	NotifySDKStopped();
	bRunThread = false;
}

bool FServiceCommunicator::SendExperienceEvent(const FString& EventId) const
{
	try
	{
		SDKServiceClient.Run<void>([&EventId](SDK_ServiceClient& Client)
		{
			const std::string EventIdString(TCHAR_TO_UTF8(*EventId));
			Client.SendExperienceEvent(EventIdString);
		});

		MIXCAST_LOG("Successfully sent experience event: %s", *EventId);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to send experience event: %s", *EventId);
		return false;
	}
}

bool FServiceCommunicator::SetAutoSnapshot(const bool bEnable, const FString& CameraId) const
{
	try
	{
		SDKServiceClient.Run<void>([bEnable, &CameraId](SDK_ServiceClient& Client)
		{
			const std::string CameraIdString(TCHAR_TO_UTF8(*CameraId));
			Client.RequestSetAutoSnapshot(CameraIdString, bEnable);
		});

		MIXCAST_LOG("Successfully set auto snapshot for camera: %s", *CameraId);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to set auto snapshot for camera: %s", *CameraId);
		return false;
	}
}

bool FServiceCommunicator::SetVideoRecording(const bool bEnable, const FString& CameraId) const
{
	try
	{
		SDKServiceClient.Run<void>([bEnable, &CameraId](SDK_ServiceClient& Client)
		{
			const std::string CameraIdString(TCHAR_TO_UTF8(*CameraId));
			Client.RequestSetVideoRecording(CameraIdString, bEnable);
		});

		MIXCAST_LOG("Set video recording for camera: %s", *CameraId);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to set video recording for camera: %s", *CameraId);
		return false;
	}
}

bool FServiceCommunicator::SetVideoStreaming(const bool bEnable, const FString& CameraId) const
{
	try
	{
		SDKServiceClient.Run<void>([bEnable, &CameraId](SDK_ServiceClient& Client)
		{
			const std::string CameraIdString(TCHAR_TO_UTF8(*CameraId));
			Client.RequestSetVideoStreaming(CameraIdString, bEnable);
		});

		MIXCAST_LOG("Successfully set video streaming for camera: %s", *CameraId);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to set video streaming for camera: %s", *CameraId);
		return false;
	}
}

bool FServiceCommunicator::TakeSnapshot(const FString& CameraId) const
{
	try
	{
		SDKServiceClient.Run<void>([&CameraId](SDK_ServiceClient& Client)
		{
			const std::string CameraIdString(TCHAR_TO_UTF8(*CameraId));
			Client.RequestTakeSnapshot(CameraIdString);
		});

		MIXCAST_LOG("Successfully took snapshot for camera: %s", *CameraId);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to take snapshot for camera: ", *CameraId);
		return false;
	}
}

void FServiceCommunicator::ShareTexture(const FString& TextureId, const UTextureRenderTarget2D* RenderTarget)
{
	MIXCAST_LOG("Queueing shared texture (%s), queue size was %d", *TextureId, SharedTextureQueueSize);
	const SharedTextureSource Source = SharedTextureSource(TextureId, RenderTarget);
	SharedTextureQueue.Enqueue(Source);
	SharedTextureQueueSize++;
}

void FServiceCommunicator::NotifySDKStarted() const
{
	try
	{
		SDKServiceClient.Run<void>([](SDK_ServiceClient& Client)
		{
			ExperienceMetadata Metadata;
			Metadata.experienceExePath = MiscUtil::ToStdString(MiscUtil::GetExecutablePath());
			Metadata.experienceTitle = MiscUtil::ToStdString(MiscUtil::GetProjectName());
			Metadata.organizationName = MiscUtil::ToStdString(MiscUtil::GetProjectName());
			Metadata.mixcastVersion = MiscUtil::ToStdString(SDK_VERSION);
			Metadata.engineVersion = MiscUtil::ToStdString(UNREAL_VERSION);
			//Metadata.projectId = PROJECT_SETTING_VAL;
			//Metadata.alphaIsPremultiplied = PROJECT_SETTING_VAL;
			Metadata.colorSpaceIsLinear = true;
			Client.NotifySdkStarted(Metadata);
		});

		//MIXCAST_LOG("Successfully notified Service that SDK has started");
	}
	catch (...)
	{
		//MIXCAST_LOG("Failed to notify Service that SDK has started");
	}
}

void FServiceCommunicator::NotifySDKStopped() const
{
	try
	{
		SDKServiceClient.Run<void>([](SDK_ServiceClient& Client)
		{
			Client.NotifySdkStopped();
		});

		//MIXCAST_LOG("Successfully notified Service that SDK has stopped");
	}
	catch (...)
	{
		//MIXCAST_LOG("Failed to notify Service that SDK has stopped");
	}
}

void FServiceCommunicator::PingService()
{
	try
	{
		SDKServiceClient.Run<void>([](SDK_ServiceClient& Client)
		{
			Client.validate_ping();
			//MIXCAST_LOG("PING SUCCEEDED");
		});
		missedPingCount = 0;
	}
	catch (...)
	{
		missedPingCount++;
		MIXCAST_LOG("PING FAILED: %d", missedPingCount);
		if (mod->IsActive() && missedPingCount >= 3) {
			AsyncTask(ENamedThreads::GameThread, [&]()
			{
				MIXCAST_LOG("MixCast Service quit abruptly");
				mod->SetActive(false);
				SDKServiceClient.EnsureTransportIsClosed();
				NotifySDKStarted();
			});
		}
	}
}

bool FServiceCommunicator::SendSharedTexture(const FString& textureId, const UTextureRenderTarget2D* RenderTarget) const
{
	FSharedTexture SharedTexture = FSharedTexture::FromRenderTarget(*RenderTarget);

	if (!SharedTexture.IsValid())
	{
		MIXCAST_LOG("Shared texture is invalid; will retry");
		return false;
	}

	try
	{
		SharedTextureClient.Run<void>([&textureId, &SharedTexture](SharedTextureCommunicationClient& Client)
		{
			SharedTex Info;
			Info.handle = SharedTexture.Handle;
			Info.format = SharedTexture.Format;
			Info.width = SharedTexture.Width;
			Info.height = SharedTexture.Height;
			const std::string CameraIdString(TCHAR_TO_UTF8(*textureId));
			Client.SharedTextureNotify(CameraIdString, Info);
		});

		MIXCAST_LOG("Successfully sent shared texture with handle %lu", SharedTexture.Handle);
		return true;
	}
	catch (...)
	{
		MIXCAST_LOG("Failed to send shared texture with handle %lu; will retry", SharedTexture.Handle);
		return false;
	}
}

void FServiceCommunicator::SendSharedTextures()
{
	TArray<SharedTextureSource> Failures = TArray<SharedTextureSource>();

	while (!SharedTextureQueue.IsEmpty())
	{
		SharedTextureSource Source;
		SharedTextureQueue.Dequeue(Source);
		SharedTextureQueueSize--;
		const FString CameraId = Source.Key;
		const UTextureRenderTarget2D* RenderTarget = Source.Value;

		if (RenderTarget == nullptr)
		{
			MIXCAST_LOG("Unable to send shared texture because render target is null");
			continue;
		}

		const bool bDidSend = SendSharedTexture(CameraId, RenderTarget);

		if (!bDidSend)
		{
			Failures.Add(Source);
		}
	}

	// Requeue failed attempts to retry on the next iteration.
	for (const auto& Source : Failures)
	{
		SharedTextureQueue.Enqueue(Source);
		SharedTextureQueueSize++;
	}
}

void FServiceCommunicator::HandleActiveChanged()
{
	if (!mod->IsActive())
	{
		SharedTextureQueue.Empty();
		SharedTextureQueueSize = 0;
	}
}