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

#include "MixCastBPFunctionLibrary.h"
#include "IMixCast.h"
#include "MixCastSdkActor.h"

void UMixCastBPFunctionLibrary::SendExperienceEvent(FString eventStr)
{
	if (!IMixCast::IsAvailable())
		return;

	IMixCast* mod = &IMixCast::Get();
	if (mod->IsActive()) {
		mod->SendExperienceEvent(eventStr);
	}
}

void UMixCastBPFunctionLibrary::SetActorVisibilityForMixCast(AActor* actor, bool visible)
{
	if (!IMixCast::IsAvailable())
		return;

	AMixCastSdkActor* sdkActor = AMixCastSdkActor::GetInstance();
	if (sdkActor == nullptr)
	{
		UE_LOG(LogMixCastSDK, Error, TEXT("Attempting to set actor visibility in a World without a MixCast SDK Actor!"));
		return;
	}

	TArray<AActor*>& hiddenActorList = sdkActor->GetHiddenActors();
	if (!visible)
	{
		if (!hiddenActorList.Contains(actor))
			hiddenActorList.Add(actor);
	}
	else
	{
		if (hiddenActorList.Contains(actor))
			hiddenActorList.Remove(actor);
	}
}