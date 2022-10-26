// Copyright Epic Games, Inc. All Rights Reserved.

#include "TreasureRaiderGameMode.h"
#include "TreasureRaiderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATreasureRaiderGameMode::ATreasureRaiderGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
