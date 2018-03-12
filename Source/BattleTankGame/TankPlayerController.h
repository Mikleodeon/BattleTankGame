// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

protected:

	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Move the barrel towards crosshair

private:

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookVectorHit(FVector&, FVector&) const;

	void GetLookDirection(FVector2D&, FVector&) const;


	FString currentPawn;

	UPROPERTY(EditAnywhere)
		float crossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float crossHairYLocation = 0.566;
	
};
