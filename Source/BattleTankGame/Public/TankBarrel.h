// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("collision"))
class BATTLETANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Pitch(float relativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float maxElevation = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float minElevation = -0.f;
	
	
};
