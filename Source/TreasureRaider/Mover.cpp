// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"
// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	StartingLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = StartingLocation + MoveOffset;
	float Speed = FVector::Distance(StartingLocation, TargetLocation) / MoveTime;
	if(ShouldMove)
	{
		UE_LOG(LogTemp, Display, TEXT("START"));
		GetOwner()->SetActorLocation(FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed));
		UE_LOG(LogTemp, Display, TEXT("FINISH"));
	}
	/*
	AActor* Owner = GetOwner();
	FString Name = Owner->GetActorNameOrLabel();
	FVector OwnerLocation = Owner->GetActorLocation();
	FString OwnerLocationString = OwnerLocation.ToCompactString();
	UE_LOG(LogTemp, Display, TEXT("OWNER:\n ADDRESS: %u"), Owner);
	UE_LOG(LogTemp, Display, TEXT("NAME: %s\n"), *(Owner->GetName()));
	UE_LOG(LogTemp, Display, TEXT("SCENE NAME: %s\n"), *Name);
	UE_LOG(LogTemp, Display, TEXT("COORDINATES: %s\n"), *OwnerLocationString);
	*/
}

