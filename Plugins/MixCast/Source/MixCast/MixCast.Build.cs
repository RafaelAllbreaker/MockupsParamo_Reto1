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

using System.IO;
using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class MixCast : ModuleRules
	{
        public MixCast(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            // Unreal generally recommends avoiding exceptions, but we need
            // to interface with Thrift which throws them.
            bEnableExceptions = true;

            // Avoid error C4541 caused by Thrift headers.
            // https://answers.unrealengine.com/questions/477792
            bUseRTTI = true;

#if UE_4_19_OR_LATER
		    PublicDefinitions.AddRange(new [] {
#else
            Definitions.AddRange(new[] {
#endif
			    "GOOGLE_PERFTOOLS_REGISTER_THREAD=0",
                "TARGET_WIN_XP=0",
                "T_GLOBAL_DEBUG_VIRTUAL=0",
                "USE_BOOST_THREAD=0",
                "_THRIFT_FUNCTIONAL_TR1_=0",
                "_ENABLE_EXTENDED_ALIGNED_STORAGE",
            });

            PublicIncludePaths.AddRange(new string[] 
                {
                    Path.Combine(ModuleDirectory,"Public"),
				});

            PrivateIncludePaths.AddRange(new string[]
                {
                    Path.Combine(ModuleDirectory,"Private"),
                });

			PublicDependencyModuleNames.AddRange(new string[]
			    {
				    "Core",
				    "CoreUObject",
                    "Engine",
                    "HeadMountedDisplay",
                    "Http",
                    "Json",
                    "JsonUtilities",
                    "RHI",
                    "RenderCore",
                });
            if (Target.bBuildEditor)
                PublicDependencyModuleNames.Add("Settings");

            AddVersionFile();
        }

        void AddVersionFile()
        {
            var VersionFilePath = Path.Combine(ModuleDirectory, "..", "..", "AdditionalResources", "MixCast_Version.txt");
#if UE_4_19_OR_LATER
		    RuntimeDependencies.Add(VersionFilePath);
#else
            var Dependency = new RuntimeDependency(VersionFilePath);
            RuntimeDependencies.Add(Dependency);
#endif
        }
    }
}
