// Fill out your copyright notice in the Description page of Project Settings.


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

void UWinHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void UWinHUD::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
}

