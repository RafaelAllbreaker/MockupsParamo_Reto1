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

#include "Generated/Service_SDK.h"

#include "CoreMinimal.h"

#include <string>

using namespace mixcast::data;
using namespace mixcast::thrift;

// Provides events to react to Service -> SDK Thrift calls.
class MIXCAST_API FServiceSDKHandler : public Service_SDKIf
{
public:
	void SetActivationState(bool active) override;

	void NotifyServiceStarted() override;

	void SendLegacyData(const std::string& dataJson) override;

	void UpdateTrackedObjectMetadata(const std::vector<TrackedObject>& trackedObjects) override;
	void UpdateCameraMetadata(const std::vector<VirtualCamera>& cameras) override;
	void UpdateViewfinderMetadata(const std::vector<Viewfinder>& viewfinders) override;
	void UpdateDesktopMetadata(const Desktop& desktop) override;

	void NotifyExternalTexturesUpdated(const std::vector<SharedTexPacket>& textureInfo) override;

	void ResetWorldOrientation() override;
	void ModifyWorldOrientation(const double degrees) override;

	void SendExperienceCommand(const std::string& cmdId) override;

	void validate_function_list(std::vector<std::string>& _return) override;
	void validate_ping() override;

	DECLARE_EVENT(FServiceSDKHandler, FServiceStartedEvent)
	FServiceStartedEvent& OnServiceStarted() { return ServiceStartedEvent; }
private:
	FServiceStartedEvent ServiceStartedEvent;
};
