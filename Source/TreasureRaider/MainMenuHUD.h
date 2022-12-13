//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: MainMenuHUD.h 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

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
	// UI Properties [
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
	// ]

	// Gameplay Handler Properties [
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerControllerRef;
	// ]
	
	// User Defined Functions [
		
	// Load Gameplay Map
	UFUNCTION()
	void OnStartClicked();
	// Load Settings Map
	UFUNCTION()
	void OnSettingsClicked();
	// Quit Game
	UFUNCTION()
	void OnQuitClicked();
	// Display Info HUD
	UFUNCTION()
	void OnInfoClicked();
	// Hide Info HUD
	UFUNCTION()
	void OnCloseClicked();
	// ]
};
