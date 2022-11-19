// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UPhysicsHandleComponent* PhysicHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
	if(!ensure(PhysicHandle != nullptr))
	{
		return;
	}
	if(PhysicHandle->GetGrabbedComponent() != nullptr)
	{
		FVector HoldLocation = GetComponentLocation() + GetForwardVector() * HoldDistance;
		PhysicHandle->SetTargetLocationAndRotation(HoldLocation, GetComponentRotation());
	}
	
}

//TAKE ITEM
void UGrabber::EnableGrab()
{
	UPhysicsHandleComponent* PhysicHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
	if(!ensure(PhysicHandle != nullptr))
	{
		return;
	}

	FVector Start = GetComponentLocation();
	FVector End = Start + (GetForwardVector() * MaxGrabDistance); 

	DrawDebugLine(GetWorld(), Start, End, FColor::Purple);
	DrawDebugSphere(GetWorld(), End, 10, 10, FColor::Blue, false, 5);

	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);
	FHitResult HitResult;
	bool HasHit = GetWorld()->SweepSingleByChannel(HitResult, Start, End, FQuat::Identity, ECC_GameTraceChannel2, Sphere);

	if(HasHit)
	{
		UE_LOG(LogTemp, Display, TEXT("HIT: %s"), *(HitResult.GetActor()->GetActorNameOrLabel()));
		DrawDebugSphere(GetWorld(), HitResult.Location, 10, 10, FColor::Green, false, 5);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10, 10, FColor::Red, false, 5);

		UPrimitiveComponent* HitComponent = HitResult.GetComponent();

		HitResult.GetActor()->Tags.Add(GrabbedTag);

		HitComponent->WakeAllRigidBodies();
		HitComponent->SetSimulatePhysics(true);

		HitResult.GetActor()->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		
		PhysicHandle->GrabComponentAtLocationWithRotation(
			HitComponent,
			NAME_None,
			HitResult.ImpactPoint,
			GetComponentRotation()
		);
	}
}

//RELEASE ITEM
void UGrabber::DisableGrab()
{
	
	UE_LOG(LogTemp, Display, TEXT("Release Grabber!!"));

	UPhysicsHandleComponent* PhysicHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	
	if(!ensure(PhysicHandle != nullptr))
	{
		return;
	}
	if(PhysicHandle->GetGrabbedComponent() != nullptr)
	{
		UPrimitiveComponent* GrabbedComponent = PhysicHandle->GetGrabbedComponent();
		GrabbedComponent->WakeAllRigidBodies();
		GrabbedComponent->GetOwner()->Tags.Remove(GrabbedTag);
		PhysicHandle->ReleaseComponent();
	}
}
