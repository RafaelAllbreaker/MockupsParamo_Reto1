// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class MockupsParamo_Reto1Target : TargetRules
{
	public MockupsParamo_Reto1Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "MockupsParamo_Reto1" } );
	}
}
