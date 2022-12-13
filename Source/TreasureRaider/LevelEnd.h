//----------------------------------------------------------
// Author: Egemen Engin
// https://github.com/egemenengin
// Name: LevelEnd.h 
// UE Version: 5.0
// Date: 08/2022
//----------------------------------------------------------

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "LevelEnd.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TREASURERAIDER_API ULevelEnd : public UBoxComponent
{
	GENERATED_BODY()
public:
	ULevelEnd();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// User Defined Functions [
		
	// If there is a overlapped actor which has a TreasureTag, return it. Otherwise nullptr.
	AActor* GetTreasureActor() const;

	//Move gates when level end
//	UFUNCTION(BlueprintCallable)
//	void OpenGates();

	// IsFinished Get Function
	UFUNCTION()
	bool GetIsFinished();
	// ]
private:
	// level End  Properties [
	UPROPERTY(EditAnyWhere)
	FName TreasureTag;

	UPROPERTY(EditAnyWhere)
    bool IsFinished = false;
	// ]
};
