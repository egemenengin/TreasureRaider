// Fill out your copyright notice in the Description page of Project Settings.


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

    
    return bSuccess;
}

void ULoseHUD::OnPlayAgainClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "FirstLevelMap");
}

void ULoseHUD::OnMainMenuClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        PlayerControllerRef->SetShowMouseCursor(false);
    }
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");
}

void ULoseHUD::OnQuitClicked()
{
    if(PlayerControllerRef != nullptr)
    {
        UKismetSystemLibrary::QuitGame(this, PlayerControllerRef, EQuitPreference::Quit, false);
    }
}

