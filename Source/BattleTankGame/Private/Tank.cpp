// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	tankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aim Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
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

//Called in blueprint: passes barrel reference to AimComponent
void ATank::SetBarrelReference(UTankBarrel* barrelToSet)
{
	tankAimComponent->SetBarrelReference(barrelToSet);
	barrel = barrelToSet;
}

//Called in blueprint: passes turret reference to AimComponent
void ATank::SetTurretReference(UTankTurret* turretToSet)
{
	tankAimComponent->SetTurretReference(turretToSet);
}

void ATank::Fire() //Called in blueprint
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));

	GetWorld()->SpawnActor<AProjectile>(Projectile_BP, barrel->GetSocketLocation(FName("endBarrel")), barrel->GetSocketRotation(FName("endBarrel")));
}



