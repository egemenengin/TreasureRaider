//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: LoseHUD.h 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

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
	// UI Properties [
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* 	PlayAgainButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* MainMenuButton;
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* QuitButton;
	// ]

	// Gameplay Handler Properties [
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class APlayerController* PlayerControllerRef;
	// ]

	// User Defined Functions [
		
	// Load Gameplay Map Again
	UFUNCTION()
	void OnPlayAgainClicked();

	// Load MainMenu Map	
	UFUNCTION()
	void OnMainMenuClicked();
	
	// Quit Game	
	UFUNCTION()
	void OnQuitClicked();
	// ]
};
