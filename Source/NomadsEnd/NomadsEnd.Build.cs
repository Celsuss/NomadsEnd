// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class NomadsEnd : ModuleRules
{
	public NomadsEnd(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        //Uncomment if you are using Slate UI
        //PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        PrivateDependencyModuleNames.AddRange(new string[] { "Json", "JsonUtilities" });

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
