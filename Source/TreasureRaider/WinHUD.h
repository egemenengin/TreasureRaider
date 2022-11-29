// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WinHUD.generated.h"

/**
 * 
 */
UCLASS()
class TREASURERAIDER_API UWinHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* QuitButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (PrivateAccessOnly = "true") )
	class APlayerController* PlayerControllerRef;

	UFUNCTION()
	void OnMainMenuClicked();

	UFUNCTION()
	void OnQuitClicked();
};
