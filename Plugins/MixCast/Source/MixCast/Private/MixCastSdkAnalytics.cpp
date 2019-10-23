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

#include "MixCastSdkAnalytics.h"
#include "MixCastLog.h"
#include "Utility/MiscUtil.hpp"

void MixCastSdkAnalytics::ReportAnalytics()
{
#if UE_EDITOR
	// Check and see if we've already reported today
	FString Date = FDateTime::Today().ToString().LeftChop(9);
	FString LastDate;
	GConfig->GetString(TEXT("MixCast"), TEXT("AnalyticsDate"), LastDate, GGameIni);

	if (Date.Compare(LastDate) == 0)
	{
		return;
	}

	GConfig->SetString(TEXT("MixCast"), TEXT("AnalyticsDate"), *Date, GGameIni);

	const FString RequestString = BuildRequestString();
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	HttpRequest->SetURL(TEXT("https://analytics.blueprintreality.com/submit-unreal.php"));
	HttpRequest->SetContentAsString(RequestString);
	HttpRequest->OnProcessRequestComplete().BindStatic(&MixCastSdkAnalytics::AnalyticsResponse);
	HttpRequest->ProcessRequest();
#endif
}

void MixCastSdkAnalytics::AnalyticsResponse(const FHttpRequestPtr Request, const FHttpResponsePtr Response, const bool bWasSuccessful)
{
	if (!Response.IsValid())
	{
		MIXCAST_LOG("Error: Analytics request failed: no response");
		return;
	}

	if (!bWasSuccessful)
	{
		const FString responseStr = Response->GetContentAsString();
		MIXCAST_LOG("Error: Analytics request failed: %s", *responseStr);
		return;
	}
}

FString MixCastSdkAnalytics::BuildRequestString()
{
	const FString CompanyName = MiscUtil::GetCompanyName();
	const FString DeviceId = MiscUtil::GetDeviceId();
	const FString ProjectName = MiscUtil::GetProjectName();
	return FString::Printf(TEXT("orgName=%s&uid=%s&projectName=%s&mixcastSDK=%s&unrealVer=%s"), *CompanyName, *DeviceId, *ProjectName, *SDK_VERSION, *UNREAL_VERSION);
}
