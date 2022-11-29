// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseHUD.generated.h"

/**
 * 
 */
UCLASS()
class TREASURERAIDER_API UPauseHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

public:
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )	
	class UButton* ResumeButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* MinutesText;
	
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* SecondsText;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnyWhere)
	bool GameIsPaused = false;

	UFUNCTION()
	void OnResumeClicked();

	UFUNCTION()
	void OnMainMenuClicked();

	UFUNCTION()
	void SetRemainingTime(float RemainingTime);

	UFUNCTION()
	void SetGameIsPaused(bool inp);

	UFUNCTION()
	bool GetGameIsPaused();
};
