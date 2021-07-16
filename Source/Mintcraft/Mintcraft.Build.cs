using UnrealBuildTool;

public class Mintcraft : ModuleRules
{
  public Mintcraft(ReadOnlyTargetRules Target) : base(Target)
  {
    bEnableUndefinedIdentifierWarnings = false;

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
        "Http",
        "Json",
        "JsonUtilities",
      }
    );

    PrivateDependencyModuleNames.AddRange(
      new string[]
      {
        "Projects",
        "InputCore",
        "CoreUObject",
        "Engine",
        "Serialization",
        "OpenSSL",
        "JsEnv",
        "Puerts",
        "RuntimeMeshComponent",
      }
    );

    DynamicallyLoadedModuleNames.AddRange(
      new string[]
      {
				// ... add any modules that your module loads dynamically here ...
			}
    );

    bEnableUndefinedIdentifierWarnings = false;
  }
}
