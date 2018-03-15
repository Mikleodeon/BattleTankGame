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
class UTankMovementComponent;

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

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Throttle)
		float forceNewtons = 62000000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//reference to attached components

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		UTankAimComponent* tankAimComponent; //sub object created at construction

	UPROPERTY(BlueprintReadOnly, Category = Movement)
		UTankMovementComponent* tankMoveComponent; //sub object created at construction

	UPROPERTY(BlueprintReadWrite, Category = Setup)
		UTankBarrel* barrel;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> Projectile_BP;


private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Variables accessable by BP
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float launchSpeed = 10000; //TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTime = 3;

	float lastFireTime = 0;

};
