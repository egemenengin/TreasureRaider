// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "TriggerSecretDoorComponent.h"

UTriggerSecretDoorComponent::UTriggerSecretDoorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    //UE_LOG(LogTemp, Display, TEXT("TRIGGER COMPONENT CONSTRUCT"));

}
// Called when the game starts
void UTriggerSecretDoorComponent::BeginPlay()
{
	Super::BeginPlay();
    //UE_LOG(LogTemp, Display, TEXT("TRIGGER COMPONENT BEGIN"));
	
}

void UTriggerSecretDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (Mover == nullptr)
    {
        return;
    }


    AActor* Actor = GetKeyActor();
    if(Actor == nullptr)
    {
       
        Mover->SetShouldMove(false);
    }
    else
    {   
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if(Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    
}
AActor* UTriggerSecretDoorComponent::GetKeyActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor* Actor: Actors)
    {
        if(Actor->ActorHasTag(KeyTag) && !Actor->ActorHasTag(GrabbedTag))
        {
            return Actor;
        }
    }
    return nullptr;
}

void UTriggerSecretDoorComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}