// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float acceptanceRadius = 8000.f;

	ATank* controlledTank;
	ATank* playerTank;

	UFUNCTION()
	void OnTankDeath();

};
