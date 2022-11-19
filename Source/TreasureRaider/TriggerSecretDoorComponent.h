// Fill out your copyright notice in the Description page of Project Settings.

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
	AActor* GetKeyActor() const;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);
	
private:
	UPROPERTY(EditAnyWhere)
	FName KeyTag;
	UPROPERTY(EditAnyWhere)
	FName GrabbedTag;
	
	UMover* Mover;
	


};
