#pragma once

#include "JsEnv.h"

#include "MintcraftEditorPCH.h"
#include "MintcraftEditorMainWindow.generated.h"

UCLASS(Blueprintable)
class UMintcraftEditorMainWindow : public UObject
{
	GENERATED_BODY()

public:
	UMintcraftEditorMainWindow(){};
	~UMintcraftEditorMainWindow() {}

public:
	/**
	UPROPERTY(EditAnywhere, Category = "Category1")
	int aaa = 1;

	UPROPERTY(EditAnywhere, Category = "Category1")
	FString bbb = "yue wu shi zhu tou!";

	UPROPERTY(EditAnywhere, Category = "Category1")
	bool ccc = false;

	UPROPERTY(EditAnywhere, Category = "Category1")
	TArray<FString> ddd;

	UPROPERTY(EditAnywhere, Category = "Category1")
	TMap<FString, int> eee;

	UPROPERTY(EditAnywhere, Category = "Category2")
	int index = 0;

	UFUNCTION(CallInEditor, Category = "Category2")
	void ExecuteMint();

	UPROPERTY(EditAnywhere, Category = "Category3")
	TSoftObjectPtr<AActor> actor;

	UPROPERTY(EditAnywhere, Category = "Category3")
	double size = 1.0;
*/
	UPROPERTY(VisibleAnywhere, Category = "Gateway")
	FString gateway = "http://127.0.0.1:7001/";

	UPROPERTY(VisibleAnywhere, Category = "Storage")
	FString storage = "ipfs";

	UPROPERTY(VisibleAnywhere, Category = "NFT")
	int contract = 0;

	UPROPERTY(EditAnywhere, Category = "NFT")
	TSoftObjectPtr<AActor> actor;

	UFUNCTION(CallInEditor, Category = "NFT")
	void ExecuteMint();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent &PropertyChangedEvent);

	virtual void OnInit();

	virtual void OnActivated();

	virtual void Shutdown();

private:
	TSharedPtr<puerts::FJsEnv> GameScript;
};
