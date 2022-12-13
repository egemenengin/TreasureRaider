//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: Grabber.h 
// UE Version: 5.0 
// Date: 08/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TREASURERAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// User Defined Functions [
	
	//	If there is a hit as a result of SweepSingleByChannel, it grabs HitResultActor
	UFUNCTION(BlueprintCallable)
	void EnableGrab();
	// If there is a grabbed actor, release it and delete GrabbedTag.
	UFUNCTION(BlueprintCallable)
	void DisableGrab();

	// ]
private:
	// Grab Properties [
	UPROPERTY(EditAnyWhere)
	float MaxGrabDistance = 220.0;
	UPROPERTY(EditAnyWhere)
	float GrabRadius = 25;
	UPROPERTY(EditAnyWhere)
	float HoldDistance = 200;	

	UPROPERTY(EditAnyWhere)
	FName GrabbedTag = "Grabbed";
	// ]
};
