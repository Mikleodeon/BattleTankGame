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

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		UTankAimComponent* tankAimComponent;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
		UTankMovementComponent* tankMoveComponent;

	//Called by engine when damage is dealt
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	) override;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//reference to attached components

private:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;

};
