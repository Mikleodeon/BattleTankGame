// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Move the barrel towards crosshair
	void AimTowardsCrosshair();

private:
	FString currentPawn;
	
};
