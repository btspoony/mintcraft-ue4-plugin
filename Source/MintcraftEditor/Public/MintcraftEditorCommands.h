#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MintcraftEditorStyle.h"

class FMintcraftEditorCommands : public TCommands<FMintcraftEditorCommands>
{
public:
	FMintcraftEditorCommands()
			: TCommands<FMintcraftEditorCommands>(TEXT("Mintcraft"), NSLOCTEXT("Contexts", "Mintcraft", "Mintcraft Plugin"), NAME_None, FMintcraftEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenPluginWindow;
};