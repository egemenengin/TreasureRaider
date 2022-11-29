// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseHUD.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

bool UPauseHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!bSuccess) return bSuccess;

    if(!ensure(ResumeButton != nullptr) ) return false;
    if(!ensure(MainMenuButton != nullptr) ) return false;
    if(!ensure(MinutesText != nullptr) ) return false;
    if(!ensure(SecondsText != nullptr) ) return false;

    ResumeButton->OnClicked.AddDynamic(this, &UPauseHUD::OnResumeClicked);
    MainMenuButton->OnClicked.AddDynamic(this, &UPauseHUD::OnMainMenuClicked);

    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);

    return bSuccess;
}

void UPauseHUD::OnResumeClicked()
{
    this->SetVisibility(ESlateVisibility::Hidden);
    this->SetIsEnabled(false);
    
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
        UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerControllerRef);
    }
    
}

void UPauseHUD::OnMainMenuClicked()
{
    this->SetVisibility(ESlateVisibility::Hidden);
    this->SetIsEnabled(false);
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void UPauseHUD::SetRemainingTime(float RemainingTime)
{
    int RemainingMin = RemainingTime / 60;
    int RemainingSec = (int) RemainingTime % 60;
    SetGameIsPaused(false);
    MinutesText->SetText(FText::AsNumber(RemainingMin));
    SecondsText->SetText(FText::AsNumber(RemainingSec));
}

void UPauseHUD::SetGameIsPaused(bool inp)
{
    GameIsPaused = inp;
}

bool UPauseHUD::GetGameIsPaused()
{
    return GameIsPaused;
}