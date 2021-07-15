#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MintcraftEditorStyle.h"

class FMintcraftEditorCommands : public TCommands<FMintcraftEditorCommands>
{
public:
	FMintcraftEditorCommands()
			: TCommands<FMintcraftEditorCommands>(TEXT("MintcraftEditor"), NSLOCTEXT("Contexts", "MintcraftEditor", "MintcraftEditor Plugin"), NAME_None, FMintcraftEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenPluginWindow;
};