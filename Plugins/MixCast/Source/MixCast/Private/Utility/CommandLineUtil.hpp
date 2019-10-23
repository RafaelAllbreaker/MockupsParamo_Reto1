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

#include "Misc/CommandLine.h"

#define MIXCAST_FLAG "mixcast"

class MIXCAST_API CommandLineUtil
{
public:
	// Checks to see if the MixCast flag was specified on the command line.
	static bool IncludesMixCastFlag()
	{
		const TCHAR* CommandLine = FCommandLine::Get();
		TArray<FString> Tokens;
		TArray<FString> Switches;
		FCommandLine::Parse(CommandLine, Tokens, Switches);
		return Switches.Contains(MIXCAST_FLAG);
	}
};
