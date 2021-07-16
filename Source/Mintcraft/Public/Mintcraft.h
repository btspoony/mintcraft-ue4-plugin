#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "GatewayAPI.h"

class FMintcraftModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<mintcraft::FGatewayAPI> GatewayAPI;
};
