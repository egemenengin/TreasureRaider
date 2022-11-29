// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TREASURERAIDER_API UMainMenuHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* StartButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* SettingsButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* QuitButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* InfoButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UCanvasPanel* InfoPanel;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* CloseButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerControllerRef;

	UFUNCTION()
	void OnStartClicked();
	UFUNCTION()
	void OnSettingsClicked();
	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void OnInfoClicked();
	UFUNCTION()
	void OnCloseClicked();
	
};
