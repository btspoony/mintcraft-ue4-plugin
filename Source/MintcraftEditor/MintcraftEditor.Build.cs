using UnrealBuildTool;

public class MintcraftEditor : ModuleRules
{
  public MintcraftEditor(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicIncludePaths.AddRange(
      new string[] {
				// ... add public include paths required here ...
			}
    );


    PrivateIncludePaths.AddRange(
      new string[] {
				// ... add other private include paths required here ...
			}
    );


    PublicDependencyModuleNames.AddRange(
      new string[]
      {
        "Core",
      }
    );

    if (Target.bBuildEditor == true)
    {
      PrivateDependencyModuleNames.AddRange(
        new string[]
        {
          "Projects",
          "InputCore",
          "UnrealEd",
          "ToolMenus",
          "CoreUObject",
          "Engine",
          "Slate",
          "SlateCore",
          "Serialization",
          "OpenSSL",
          "JsEnv",
          "Puerts",
          // mintcraft runtime module
          "Mintcraft",
        }
      );
    }

    DynamicallyLoadedModuleNames.AddRange(
      new string[]
      {
				// ... add any modules that your module loads dynamically here ...
			}
    );
  }
}
