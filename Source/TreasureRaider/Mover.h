//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: Mover.h 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TREASURERAIDER_API UMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// Move Properties [
	UPROPERTY(EditAnyWhere)
	FVector MoveOffset;

	UPROPERTY()
	FVector StartingLocation;

	UPROPERTY(EditAnyWhere)
	float MoveTime = 4;
	
	UPROPERTY(EditAnyWhere)
	bool ShouldMove = false;
	// ]
public: 
	// User Defined Functions [	
		
	// ShouldMove Set Function
	void SetShouldMove(bool NewShouldMove);
	// ]
};
