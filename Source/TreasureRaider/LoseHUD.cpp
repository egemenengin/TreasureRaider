//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: LoseHUD.cpp
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------


#include "LoseHUD.h"
#include "Runtime/UMG/Public/UMG.h"

bool ULoseHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }
    if(!ensure(PlayAgainButton != nullptr) ) return false;
    if(!ensure(MainMenuButton != nullptr) ) return false;
    if(!ensure(QuitButton != nullptr) ) return false;

    PlayAgainButton->OnClicked.AddDynamic(this, &ULoseHUD::OnPlayAgainClicked);
    MainMenuButton->OnClicked.AddDynamic(this, &ULoseHUD::OnMainMenuClicked);
    QuitButton->OnClicked.AddDynamic(this, &ULoseHUD::OnQuitClicked);
    return bSuccess;
}

// Load Gameplay Map Again
void ULoseHUD::OnPlayAgainClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "FirstLevelMap");
}

// Load MainMenu Map
void ULoseHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

// Quit Game
void ULoseHUD::OnQuitClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}

