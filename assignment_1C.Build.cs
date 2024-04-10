// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class assignment_1C : ModuleRules
{
	public assignment_1C(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" , "UMG"});
		
		PrivateDependencyModuleNames.AddRange(new string[]{"Slate", "SlateCore"});
	}
}
