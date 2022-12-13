//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: PauseHUD.h
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

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
	// UI Properties [
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )	
	class UButton* ResumeButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* MinutesText;
	
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* SecondsText;
	// ]

	// Gameplay Handler Properties [	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnyWhere)
	bool GameIsPaused = false;
	// ]

	// User Defined Functions [
		
	// Hide PauseHUD and resume playing
	UFUNCTION()
	void OnResumeClicked();

	// Load MainMenu Map
	UFUNCTION()
	void OnMainMenuClicked();
	
	// Set MinutesText and SecondsText
	UFUNCTION()
	void SetRemainingTime(float RemainingTime);

	// GameIsPaused Set Function
	UFUNCTION()
	void SetGameIsPaused(bool inp);

	// GameIsPaused Get Function
	UFUNCTION()
	bool GetGameIsPaused();
	// ]
};
