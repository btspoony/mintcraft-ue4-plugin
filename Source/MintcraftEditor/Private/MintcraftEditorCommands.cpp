#include "MintcraftEditorCommands.h"

#define LOCTEXT_NAMESPACE "FMintcraftEditorModule"

void FMintcraftEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "Mintcraft", "Bring up Mintcraft window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
