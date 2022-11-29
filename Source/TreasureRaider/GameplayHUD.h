// Fill out your copyright notice in the Description page of Project Settings.

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
	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UTextBlock* MinutesText;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )	
	class UTextBlock* SecondsText;

	UPROPERTY(EditAnyWhere, meta = (BindWidget) )
	class UProgressBar* RemainingProgressBar;

	UFUNCTION()
	void HandleDecreaseTime(float TotalTime, float RemainingTime);

};