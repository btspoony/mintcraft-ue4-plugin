#pragma once

#include "CoreMinimal.h"

namespace mintcraft
{
  class IWalletsLoader
  {
  public:
    virtual bool LoadNames(TArray<FString> &Names) = 0;

    virtual bool Load(const FString &InName, TArray<uint8> &MasterSeed, TArray<uint8> &Password) = 0;

    virtual FString &GetSecretRoot() = 0;

    virtual ~IWalletsLoader() {}
  };

  class WalletLoader : public IWalletsLoader
  {
  public:
    explicit WalletLoader(const FString &InSecretRoot) : SecretsRoot(InSecretRoot) {}

    bool LoadNames(TArray<FString> &Names) override;

    bool Load(const FString &InName, TArray<uint8> &MasterSeed, TArray<uint8> &Password) override;

    FString &GetSecretRoot() override;

  private:
    bool CheckExists(const FString &PathIn, FString &Path, FString &AbsolutePath);

    FString SecretsRoot;
  };
}