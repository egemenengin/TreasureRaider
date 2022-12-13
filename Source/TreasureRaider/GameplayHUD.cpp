//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: GameplayHUD.cpp
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#include "GameManager.h"
#include "GameplayHUD.h"
#include "Runtime/UMG/Public/UMG.h"

bool UGameplayHUD::Initialize()
{
    bool bSuccess = Super::Initialize();
    if(!bSuccess) return false;

    if(!ensure(MinutesText != nullptr)) return false;
    if(!ensure(SecondsText != nullptr)) return false;
    if(!ensure(RemainingProgressBar != nullptr)) return false;

    return bSuccess;

}

// Set Min and Sec Time Texts and Set Percent of Time Progress Bar
void UGameplayHUD::HandleDecreaseTime(float TotalTime, float RemainingTime)
{
    int remainingMin = RemainingTime / 60;
    int remainingSec = (int)RemainingTime % 60;
    
    RemainingProgressBar->SetPercent(RemainingTime / TotalTime);
    MinutesText->SetText(FText::AsNumber(remainingMin));
    SecondsText->SetText(FText::AsNumber(remainingSec));
}
