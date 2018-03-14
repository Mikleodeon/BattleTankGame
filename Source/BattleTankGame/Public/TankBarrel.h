// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Pitch(float deltaPitch);

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float maxDegreesPerSecond = 20.f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float maxElevation = 40.f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float minElevation = -0.f;
	
	
};
