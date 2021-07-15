#include "MintcraftEditor.h"
#include "MintcraftEditorStyle.h"
#include "MintcraftEditorCommands.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "LevelEditor.h"
#include "ToolMenus.h"
#include "MintcraftEditorMainWindow.h"

static const FName MintcraftEditorTabName("Mintcraft");

#define LOCTEXT_NAMESPACE "FMintcraftEditorModule"

void FMintcraftEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FMintcraftEditorStyle::Initialize();
	FMintcraftEditorStyle::ReloadTextures();

	FMintcraftEditorCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
			FMintcraftEditorCommands::Get().OpenPluginWindow,
			FExecuteAction::CreateRaw(this, &FMintcraftEditorModule::PluginButtonClicked),
			FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMintcraftEditorModule::RegisterMenus));

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MintcraftEditorTabName, FOnSpawnTab::CreateRaw(this, &FMintcraftEditorModule::OnSpawnPluginTab)).SetDisplayName(LOCTEXT("FMintcraftEditorTabTitle", "Mintcraft")).SetMenuType(ETabSpawnerMenuType::Hidden);

	MainWindow = NewObject<UMintcraftEditorMainWindow>(GetTransientPackage());
	MainWindow->AddToRoot();
	MainWindow->OnInit();
}

void FMintcraftEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	MainWindow->Shutdown();

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMintcraftEditorStyle::Shutdown();

	FMintcraftEditorCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MintcraftEditorTabName);
}

static bool ShouldShowProperty(const FPropertyAndParent &PropertyAndParent, bool bHaveTemplate)
{
	const FProperty &Property = PropertyAndParent.Property;

	if (bHaveTemplate)
	{
		const UClass *PropertyOwnerClass = Property.GetOwner<const UClass>();
		const bool bDisableEditOnTemplate = PropertyOwnerClass && PropertyOwnerClass->IsNative() && Property.HasAnyPropertyFlags(CPF_DisableEditOnTemplate);
		if (bDisableEditOnTemplate)
		{
			return false;
		}
	}
	return true;
}

TSharedRef<SDockTab> FMintcraftEditorModule::OnSpawnPluginTab(const FSpawnTabArgs &SpawnTabArgs)
{
	FDetailsViewArgs Args;
	Args.bHideSelectionTip = true;
	Args.bLockable = false;
	TArray<UObject *> ObjectsToView;
	ObjectsToView.Add(MainWindow);

	FPropertyEditorModule &PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	TSharedRef<IDetailsView> DetailView = PropertyEditorModule.CreateDetailView(Args);

	bool bHaveTemplate = false;
	for (int32 i = 0; i < ObjectsToView.Num(); i++)
	{
		if (ObjectsToView[i] != NULL && ObjectsToView[i]->IsTemplate())
		{
			bHaveTemplate = true;
			break;
		}
	}

	DetailView->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateStatic(&ShouldShowProperty, bHaveTemplate));

	DetailView->SetObjects(ObjectsToView);

	return SNew(SDockTab)
			.TabRole(ETabRole::NomadTab)
					[DetailView];
}

void FMintcraftEditorModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MintcraftEditorTabName);

	// activate js env
	MainWindow->OnActivated();
}

void FMintcraftEditorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu *Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection &Section = Menu->FindOrAddSection("Mintcraft");
			Section.AddMenuEntryWithCommandList(FMintcraftEditorCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu *ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection &Section = ToolbarMenu->FindOrAddSection("Mintcraft");
			{
				FToolMenuEntry &Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMintcraftEditorCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMintcraftEditorModule, MintcraftEditor)