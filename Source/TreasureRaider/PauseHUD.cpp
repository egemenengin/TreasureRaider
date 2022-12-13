//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: PauseHUD.cpp 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

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

// Hide PauseHUD and resume playing
void UPauseHUD::OnResumeClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
        UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerControllerRef);
    }

    SetGameIsPaused(false);
    this->SetVisibility(ESlateVisibility::Hidden);
    this->SetIsEnabled(false);
}

// Load MainMenu Map
void UPauseHUD::OnMainMenuClicked()
{
    this->SetVisibility(ESlateVisibility::Hidden);
    this->SetIsEnabled(false);
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

// Set MinutesText and SecondsText
void UPauseHUD::SetRemainingTime(float RemainingTime)
{
    int RemainingMin = RemainingTime / 60;
    int RemainingSec = (int) RemainingTime % 60;

    MinutesText->SetText(FText::AsNumber(RemainingMin));
    SecondsText->SetText(FText::AsNumber(RemainingSec));
}

// GameIsPaused Set Function
void UPauseHUD::SetGameIsPaused(bool inp)
{
    GameIsPaused = inp;
}

// GameIsPaused Get Function
bool UPauseHUD::GetGameIsPaused()
{
    return GameIsPaused;
}