// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimComponent;
class UTankTurret;
class AProjectile;
class UBulletMovement;

UCLASS()
class BATTLETANKGAME_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector hitLocation);

	UFUNCTION(BlueprintCallable, Category = Fire)
		void Fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//reference to attached components
	UTankAimComponent* tankAimComponent;
	UTankBarrel* barrel;

	//setters for references
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* barrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* turretToSet);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> Projectile_BP;

	//Variables accessable by BP
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float launchSpeed = 10000; //TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTime = 3;

	float lastFireTime = 0;
	
};
