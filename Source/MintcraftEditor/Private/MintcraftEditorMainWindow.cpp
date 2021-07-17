#include "MintcraftEditorMainWindow.h"

void UMintcraftEditorMainWindow::OnInit()
{
    GameScript = MakeShared<puerts::FJsEnv>();
    //GameScript = MakeShared<puerts::FJsEnv>(std::make_unique<puerts::DefaultJSModuleLoader>(TEXT("JavaScript")), std::make_shared<puerts::FDefaultLogger>(), 8080);
    //GameScript->WaitDebugger();
}

void UMintcraftEditorMainWindow::OnActivated()
{
    TArray<TPair<FString, UObject *> > Arguments;
    Arguments.Add(TPair<FString, UObject *>(TEXT("MintcraftEditor"), this));

    GameScript->Start("Mintcraft/Entry", Arguments);
}

void UMintcraftEditorMainWindow::Shutdown()
{
    GameScript.Reset();
}

void UMintcraftEditorMainWindow::PostEditChangeProperty(struct FPropertyChangedEvent &PropertyChangedEvent)
{
    // FString PropertyName = PropertyChangedEvent.Property->GetName();
    // FString MemberPropertyName = PropertyChangedEvent.MemberProperty->GetName();

    // if (PropertyName == TEXT("size"))
    // {
    //     if (actor)
    //     {
    //         if (actor->GetRootComponent())
    //         {
    //             actor->GetRootComponent()->SetWorldScale3D(FVector(size / 1000, size / 1000, size / 1000));
    //         }
    //     }
    // }
}

void UMintcraftEditorMainWindow::ExecuteMint()
{
    UE_LOG(MintcraftLog, Verbose, TEXT("Executing NFT Mint."));
}