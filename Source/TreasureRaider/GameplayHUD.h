//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: GameplayHUD.h
// UE Version: 5.0 
// Date: 08/2022
//----------------------------------------------------------

#pragma once


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayHUD.generated.h"

/**
 * 
 */
UCLASS()
class TREASURERAIDER_API UGameplayHUD : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

public:
	// UI Properties [
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* MinutesText;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )	
	class UTextBlock* SecondsText;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UProgressBar* RemainingProgressBar;
	// ]

	// User Defined Functions [
		
	// Set Min and Sec Time Texts and Set Percent of Time Progress Bar
	UFUNCTION()
	void HandleDecreaseTime(float TotalTime, float RemainingTime);
	// ]
};