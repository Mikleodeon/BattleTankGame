// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent), Category = Movement)
class BATTLETANKGAME_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Movement)
		void IntendMoveForward(float relativeSpeed);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTrackReference(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet);

private:

	UTankTrack* leftTrack;
	UTankTrack* rightTrack;
	
};
