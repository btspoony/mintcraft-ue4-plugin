
#include "WalletsLoader.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Engine.h"

namespace mintcraft
{

  bool WalletLoader::LoadNames(TArray<FString> &Names)
  {
    // TODO
    return false;
  }

  bool WalletLoader::Load(const FString &InName, TArray<uint8> &MasterSeed, TArray<uint8> &Password)
  {
    // TODO
    return false;
  }

  bool WalletLoader::CheckExists(const FString &PathIn, FString &Path, FString &AbsolutePath)
  {
    IPlatformFile &PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
    FString NormalizedPath = puerts::PathNormalize(PathIn);
    if (PlatformFile.FileExists(*NormalizedPath))
    {
      AbsolutePath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead(*NormalizedPath);
      Path = NormalizedPath;
      return true;
    }

    return false;
  }

  FString &WalletLoader::GetSecretRoot()
  {
    return SecretsRoot;
  }
}