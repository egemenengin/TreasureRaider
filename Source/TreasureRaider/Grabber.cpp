// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UGrabber::DisableGrab()
{
	UE_LOG(LogTemp, Display, TEXT("Release Grabber!!"));
}

void UGrabber::EnableGrab()
{
	FVector Start = GetComponentLocation();
	FVector End = Start + (GetForwardVector() * MaxGrabDistance); 
	DrawDebugLine(GetWorld(), Start, End, FColor::Purple);
	
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, Sphere);
	if(HasHit)
	{
		UE_LOG(LogTemp, Display, TEXT("HIT: %s"), *(HitResult.GetActor()->GetActorNameOrLabel()));

	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("DOESNT HIT!!!"));

	}
}