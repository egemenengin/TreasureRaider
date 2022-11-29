// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayHUD.h"
#include "PauseHUD.h"
#include "LoseHUD.h"
#include "WinHUD.h"
#include "GameManager.generated.h"

UENUM(BlueprintType)
enum EGameStatus
{
	Play,
	Pause,
	Win,
	Lose
};
UCLASS()
class TREASURERAIDER_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnyWhere)
	bool TimerStarted;
	UPROPERTY(EditAnyWhere)
	float TotalTime = 120;
	UPROPERTY(EditAnyWhere)
	float RemainingTime = 120;

	UPROPERTY(EditAnyWhere)
	bool GameFinished;

	TEnumAsByte<EGameStatus> CurGameStatus;

	FTimerHandle TimerHandle;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	APlayerController* PlayerControllerRef;

// UI PROPERTIES
	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UGameplayHUD> GameplayHUDClass;
	class UGameplayHUD* GameplayHUD;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UPauseHUD> PauseHUDClass;
	class UPauseHUD* PauseHUD;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<class UWinHUD> WinHUDClass;
	class UWinHUD* WinHUD;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<class ULoseHUD> LoseHUDClass;
	class ULoseHUD* LoseHUD;

public:

	UFUNCTION()
	void WinGame();

	UFUNCTION()
	void LoseGame();

	UFUNCTION()
	void PauseGame();

	UFUNCTION()
	void SetGameStatus(EGameStatus NewGameStatus);

	UFUNCTION()
	void TimeManager();

};
