// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseHUD.generated.h"

/**
 * 
 */
UCLASS()
class TREASURERAIDER_API ULoseHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* 	PlayAgainButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* QuitButton;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class APlayerController* PlayerControllerRef;

	UFUNCTION()
	void OnPlayAgainClicked();
	UFUNCTION()
	void OnMainMenuClicked();
	UFUNCTION()
	void OnQuitClicked();

};
