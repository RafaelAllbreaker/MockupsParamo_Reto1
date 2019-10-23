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

#include "Logging/LogMacros.h"

// A semicolon is required after this definition for the plugin to compile in Unreal 4.17.
DECLARE_LOG_CATEGORY_EXTERN(LogMixCastSDK, Log, All);

#define MIXCAST_LOG(format, ...) UE_LOG(LogMixCastSDK, Log, TEXT(format), __VA_ARGS__)
