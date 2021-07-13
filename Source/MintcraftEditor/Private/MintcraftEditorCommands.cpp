// Copyright Epic Games, Inc. All Rights Reserved.

#include "MintcraftEditorCommands.h"

#define LOCTEXT_NAMESPACE "FMintcraftEditorModule"

void FMintcraftEditorCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MintcraftEditor", "Bring up MintcraftEditor window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
