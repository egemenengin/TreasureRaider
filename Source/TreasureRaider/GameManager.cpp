// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	check(PlayerControllerRef);

	CurGameStatus = EGameStatus::Play;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerControllerRef);
	
	if(GameplayHUDClass && WinHUDClass && LoseHUDClass && PauseHUDClass)
	{
		GameplayHUD = CreateWidget<UGameplayHUD>(PlayerControllerRef, GameplayHUDClass);
		check(GameplayHUD);
		GameplayHUD->AddToPlayerScreen();

		WinHUD = CreateWidget<UWinHUD>(PlayerControllerRef, WinHUDClass);
		check(WinHUD);
		WinHUD->AddToPlayerScreen();

		LoseHUD = CreateWidget<ULoseHUD>(PlayerControllerRef, LoseHUDClass);
		check(LoseHUD);
		LoseHUD->AddToPlayerScreen();

		PauseHUD = CreateWidget<UPauseHUD>(PlayerControllerRef, PauseHUDClass);
		check(PauseHUD);
		PauseHUD->AddToPlayerScreen();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Undeclared HUDClass"));
	}
	PlayerControllerRef->SetShowMouseCursor(false);
	GameplayHUD->HandleDecreaseTime(TotalTime, RemainingTime);
	
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!GameFinished)
	{
		switch(CurGameStatus)
		{
			case EGameStatus::Pause:
				if(!PauseHUD->GetGameIsPaused())
				{
					SetGameStatus(EGameStatus::Play);
				}
				else if(!PauseHUD->GetIsEnabled())
				{
					PauseHUD->SetRemainingTime(RemainingTime);	
					PauseGame();
				}
				else if(PlayerControllerRef->WasInputKeyJustPressed(EKeys::P) )
				{
					PauseHUD->OnResumeClicked();
				}
				//else nothing to do
				break;
			case EGameStatus::Win:
				WinGame();
				break;
			case EGameStatus::Lose:
				LoseGame();
				break;
			case EGameStatus::Play:
				if(LevelEnd->GetIsFinished())
				{
					SetGameStatus(EGameStatus::Win);
				}
				else if(PlayerControllerRef->WasInputKeyJustPressed(EKeys::P))
				{
					SetGameStatus(EGameStatus::Pause);
					PauseHUD->SetGameIsPaused(true);
				}
				else if(!TimerStarted)
				{
					TimerStarted = true;
					GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGameManager::TimeManager, 1, false);
					if(RemainingTime <= 0)
					{
						SetGameStatus(EGameStatus::Lose);
					}
				}
				break;
			default:
				UE_LOG(LogTemp, Error, TEXT("Undefined Game Status!"));

		}
	}
	//else nothing to do cuz game is finished.
	
}

void AGameManager::WinGame()
{
	PlayerControllerRef->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef);
	
	WinHUD->SetVisibility(ESlateVisibility::Visible);
	WinHUD->SetIsEnabled(true);
	
	GameFinished = true;
	TimerStarted = false;
}

void AGameManager::LoseGame()
{
	PlayerControllerRef->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef);

	LoseHUD->SetVisibility(ESlateVisibility::Visible);
	LoseHUD->SetIsEnabled(true);

	GameFinished = true;
	TimerStarted = false;
}

void AGameManager::PauseGame()
{
	PlayerControllerRef->SetShowMouseCursor(true);
	UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerControllerRef);

	PauseHUD->SetVisibility(ESlateVisibility::Visible);
	PauseHUD->SetIsEnabled(true);


}
void AGameManager::SetGameStatus(EGameStatus NewGameStatus)
{
	CurGameStatus = NewGameStatus;
}

void AGameManager::TimeManager()
{
	GameplayHUD->HandleDecreaseTime(TotalTime, RemainingTime);
	RemainingTime -= 1;
	TimerStarted = false;
}

void AGameManager::SetLevelEnd(ULevelEnd* CurLevelEnd)
{
	LevelEnd = CurLevelEnd;
}
