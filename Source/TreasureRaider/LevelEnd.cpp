//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: LevelEnd.cpp
// UE Version: 5.0 
// Date: 08/2022
//----------------------------------------------------------


#include "LevelEnd.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

ULevelEnd::ULevelEnd()
{
    PrimaryComponentTick.bCanEverTick = true;
    //UE_LOG(LogTemp, Display, TEXT("TRIGGER COMPONENT CONSTRUCT"));

}

// Called when the game starts
void ULevelEnd::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ULevelEnd::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    AActor* Actor = GetTreasureActor();
    if(Actor != nullptr)
    {
        IsFinished = true;
    }
}

//Treasure Actor Get Function
AActor* ULevelEnd::GetTreasureActor() const
{
    TArray<AActor*> Actors;
    
    GetOverlappingActors(Actors);
    for(AActor* Actor: Actors)
    {
        if(Actor->ActorHasTag(TreasureTag) )
        {
            return Actor;
        }
    }
    return nullptr;
}

// IsFinished Get Function
bool ULevelEnd::GetIsFinished()
{
    return IsFinished;
}