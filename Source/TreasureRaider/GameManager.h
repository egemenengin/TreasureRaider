//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: GameManager.h
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

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
#include "LevelEnd.h"
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

	// Time PROPERTIES [
	UPROPERTY(EditAnyWhere)
	bool TimerStarted;

	UPROPERTY(EditAnyWhere)
	float TotalTime = 120;

	UPROPERTY(EditAnyWhere)
	float RemainingTime = 120;

	UPROPERTY(EditAnyWhere)
	bool GameFinished = false;

	FTimerHandle TimerHandle;
	// ]

	// Gameplay Handlers [
	TEnumAsByte<EGameStatus> CurGameStatus;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	APlayerController* PlayerControllerRef;

	UPROPERTY(EditAnyWhere)
	class ULevelEnd* LevelEnd;
	// ]

	// UI Properties [
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
	// ]
public:
	// User Defined Functions [
		
	//Call SetGameStatus to set Current Game Status to Win and Display WinHUD
	UFUNCTION()
	void WinGame();

	//Call SetGameStatus to set Current Game Status to Lose and Display LoseHUD
	UFUNCTION()
	void LoseGame();

	// Call SetGameStatus to set Current Game Status to Pause and Display PauseHUD
	UFUNCTION()
	void PauseGame();

	// CurGameStatus Set Function 
	UFUNCTION()
	void SetGameStatus(EGameStatus NewGameStatus);

	// Call HandleDecreaseTime by GameplayHUD and Decrease RemainingTime
	UFUNCTION()
	void TimeManager();

	// LevelEnd Set Function 
	UFUNCTION(BlueprintCallable)
	void SetLevelEnd(ULevelEnd* CurLevelEnd);
	// ]
};
