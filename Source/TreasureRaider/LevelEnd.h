// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "LevelEnd.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TREASURERAIDER_API ULevelEnd : public UBoxComponent
{
	GENERATED_BODY()
public:
	ULevelEnd();
protected:
	virtual void BeginPlay() override;
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetTreasureActor() const;

//	UFUNCTION(BlueprintCallable)
//	void OpenGates();

	UFUNCTION()
	bool GetIsFinished();

private:
	UPROPERTY(EditAnyWhere)
	FName TreasureTag;

	UPROPERTY(EditAnyWhere)
    bool IsFinished = false;
};
