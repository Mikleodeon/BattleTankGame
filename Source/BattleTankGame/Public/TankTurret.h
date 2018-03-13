// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Yaw(float deltaYaw);

private:

	UPROPERTY(EditAnywhere, Category = Setup)
		float maxDegreesPerSecond = 60.f;
	
	
	
	
};
