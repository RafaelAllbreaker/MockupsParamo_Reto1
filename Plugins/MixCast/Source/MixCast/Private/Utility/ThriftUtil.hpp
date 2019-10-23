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

#include "MixCastLog.h"
#include "MathUtil.hpp"
#include "Generated/Math_types.h"
#include "Thrift/TOutput.h"

#include <string>

using namespace apache::thrift;

namespace mixcast { namespace thrift {

class MIXCAST_API ThriftUtil
{
public:
	// Creates the Windows pipe name with server prefix.
	// https://docs.microsoft.com/en-us/windows/desktop/ipc/pipe-names
	static std::string GetFullPipeName(const std::string& PipeName)
	{
		return R"(\\.\pipe\)" + PipeName;
	}

	static void SetUpLogCallback()
	{
		GlobalOutput.setOutputFunction([](const char* Message)
		{
			const FString String = FString(UTF8_TO_TCHAR(Message));
			MIXCAST_LOG("[Thrift] %s", *String);
		});
	}

	static FVector ThriftVectorToUnreal(const Vector3 &UnityPosition)
	{
		return MathUtil::UnityPositionToUnreal({ (float)UnityPosition.x, (float)UnityPosition.y, (float)UnityPosition.z });
	}
	static FQuat ThriftQuatToUnreal(const Quaternion &UnityRotation)
	{
		return MathUtil::UnityRotationToUnreal({ (float)UnityRotation.x, (float)UnityRotation.y, (float)UnityRotation.z, (float)UnityRotation.w });
	}
};

} }