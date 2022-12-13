//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: MainMenuHUD.cpp
// UE Version: 5.0 
// Date: 08/2022
//----------------------------------------------------------


#include "MainMenuHUD.h"
#include "Runtime/UMG/Public/UMG.h"

bool UMainMenuHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!bSuccess) return bSuccess;
    PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(true);
    }

    if(!ensure(StartButton != nullptr) ) return false;
    if(!ensure(SettingsButton != nullptr) ) return false;
    if(!ensure(QuitButton != nullptr) ) return false;

    if(!ensure(InfoButton != nullptr) ) return false;
    if(!ensure(InfoPanel != nullptr) ) return false;
    if(!ensure(CloseButton != nullptr) ) return false;

    StartButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnStartClicked);
    SettingsButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnSettingsClicked);
    QuitButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnQuitClicked);
    
    InfoButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnInfoClicked);
    CloseButton->OnClicked.AddDynamic(this, &UMainMenuHUD::OnCloseClicked);
    

    return bSuccess;
}

// Load Gameplay Map
void UMainMenuHUD::OnStartClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "FirstLevelMap");
}

// Load Settings Map
void UMainMenuHUD::OnSettingsClicked()
{
    //UGameplayStatics::OpenLevel(GetWorld(), "");
}

// Quit Game
void UMainMenuHUD::OnQuitClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}

// Display Info HUD
void UMainMenuHUD::OnInfoClicked()
{
    InfoPanel->SetVisibility(ESlateVisibility::Visible);
    InfoPanel->SetIsEnabled(true);
}

// Hide Info HUD
void UMainMenuHUD::OnCloseClicked()
{
    InfoPanel->SetVisibility(ESlateVisibility::Hidden);
    InfoPanel->SetIsEnabled(false);
}