// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEnd.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"

ULevelEnd::ULevelEnd()
{
    PrimaryComponentTick.bCanEverTick = true;
    //UE_LOG(LogTemp, Display, TEXT("TRIGGER COMPONENT CONSTRUCT"));

}

void ULevelEnd::BeginPlay()
{
    Super::BeginPlay();

}

void ULevelEnd::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    AActor* Actor = GetTreasureActor();
    if(Actor != nullptr)
    {
        IsFinished = true;
    }
}
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
bool ULevelEnd::GetIsFinished()
{
    return IsFinished;
}