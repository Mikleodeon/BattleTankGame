// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimComponent;

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

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimComponent(UTankAimComponent* AimComp);

private:

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&) const;

	bool GetLookVectorHit(FVector&, FVector&) const;

	void GetLookDirection(FVector2D&, FVector&) const;


	FString currentPawn;

	UPROPERTY(EditDefaultsOnly)
		float crossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
		float crossHairYLocation = 0.566;
	
};
