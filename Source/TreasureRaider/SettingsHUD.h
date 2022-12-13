//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: SettingsHUD.h
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingsHUD.generated.h"

/**
 * 
 */
UCLASS()
class TREASURERAIDER_API USettingsHUD : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	// UI Properties [
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class USlider* MusicSlider;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class USlider* SoundSlider;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UButton* SaveAndBackButton;
	// ]
};
