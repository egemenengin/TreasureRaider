//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: TriggerSecretDoorComponent.cpp
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#include "TriggerSecretDoorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"


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

// Return Overlapped Actor
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

// Mover Set Function
void UTriggerSecretDoorComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}