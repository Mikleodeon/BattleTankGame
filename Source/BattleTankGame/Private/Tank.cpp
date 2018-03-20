// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "BulletMovement.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	barrel = FindComponentByClass<UTankBarrel>();
	tankAimComponent = FindComponentByClass<UTankAimComponent>();
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector targetLocation)
{
	FString tankName = GetName();
	tankAimComponent->Aim(targetLocation, tankName, launchSpeed);
}

void ATank::Fire() //Called in blueprint
{
	float time = GetWorld()->GetTimeSeconds() + 3;
	bool isReloaded = (time - lastFireTime) > reloadTime;
	if (isReloaded)
	{
		AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(Projectile_BP, barrel->GetSocketLocation(FName("endBarrel")),
			barrel->GetSocketRotation(FName("endBarrel")));

		if (!projectile) { return; }

		projectile->launchProjectile(launchSpeed);
		lastFireTime = time;
	}
}



