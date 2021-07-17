#include "Mintcraft.h"
#include "GatewayAPI.h"

#define LOCTEXT_NAMESPACE "FMintcraftModule"

void FMintcraftModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	GatewayAPI = MakeShared<mintcraft::FGatewayAPI>();
}

void FMintcraftModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMintcraftModule, Mintcraft)

DEFINE_LOG_CATEGORY(MintcraftLog);