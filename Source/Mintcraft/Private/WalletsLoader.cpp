
#include "WalletsLoader.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Engine.h"

namespace mintcraft
{
  static FString PathNormalize(const FString& PathIn)
  {
    TArray<FString> PathFrags;
    PathIn.ParseIntoArray(PathFrags, TEXT("/"));
    Algo::Reverse(PathFrags);
    TArray<FString> NewPathFrags;
    bool FromRoot = PathIn.StartsWith(TEXT("/"));
    while (PathFrags.Num() > 0) {
      FString E = PathFrags.Pop();
      if (E != TEXT("") && E != TEXT("."))
      {
        if (E == TEXT("..") && NewPathFrags.Num() > 0 && NewPathFrags.Last() != TEXT("..")) {
          NewPathFrags.Pop();
        }
        else {
          NewPathFrags.Push(E);
        }
      }
    }
    if (FromRoot)
    {
      return TEXT("/") + FString::Join(NewPathFrags, TEXT("/"));
    }
    else
    {
      return FString::Join(NewPathFrags, TEXT("/"));
    }
  }

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
    FString NormalizedPath = PathNormalize(PathIn);
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