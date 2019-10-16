// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class MockupsParamo_Reto1EditorTarget : TargetRules
{
	public MockupsParamo_Reto1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "MockupsParamo_Reto1" } );
	}
}
