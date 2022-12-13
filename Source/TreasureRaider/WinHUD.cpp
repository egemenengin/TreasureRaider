//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: WinHUD.cpp
// UE Version: 5.0 
// Date: 08/2022
//----------------------------------------------------------


#include "WinHUD.h"
#include "Runtime/UMG/Public/UMG.h"

bool UWinHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }
    if(!ensure(MainMenuButton != nullptr) ) return false;
    if(!ensure(QuitButton != nullptr) ) return false;

    MainMenuButton->OnClicked.AddDynamic(this, &UWinHUD::OnMainMenuClicked);
    QuitButton->OnClicked.AddDynamic(this, &UWinHUD::OnQuitClicked);
    return bSuccess;
}

// Load MainMenu Map
void UWinHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

// Quit Game
void UWinHUD::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
}

