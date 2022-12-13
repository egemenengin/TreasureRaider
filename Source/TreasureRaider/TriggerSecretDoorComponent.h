//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: TriggerSecretDoorComponent.h 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "TriggerSecretDoorComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TREASURERAIDER_API UTriggerSecretDoorComponent : public UBoxComponent
{
	GENERATED_BODY()
public:
	UTriggerSecretDoorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// User Defined Functions [
		
	// If there is a overlapped actor which has a KeyTag and doesn't have GrabbedTag, return it. Otherwise nullptr.
	AActor* GetKeyActor() const;
	
	// Mover Set Function
	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);
	// ]
	
private:
	// Trigger Properties [
	UPROPERTY(EditAnyWhere)
	FName KeyTag;
	UPROPERTY(EditAnyWhere)
	FName GrabbedTag;
	
	UMover* Mover;
	// ]


};
