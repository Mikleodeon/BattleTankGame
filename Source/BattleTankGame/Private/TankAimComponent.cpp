// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "BulletMovement.h"


// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimComponent::SetComponentReferences(UTankBarrel* barrelToSet, UTankTurret* TurretToSet)
{
	barrel = barrelToSet;
	turret = TurretToSet;
}

// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("Aim Comp"));
}

void UTankAimComponent::Aim(FVector targetLocation, FString& tankName, float launchSpeed)
{
	if (!barrel) { return; }

	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("endBarrel"));

	//Calculate the outLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, targetLocation, launchSpeed, false, 0.f, 0.f, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector aimDirection = outLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(aimDirection.Rotation());
		MoveTurret(aimDirection.Rotation());
	}
}

void UTankAimComponent::MoveBarrel(FRotator aimRotation)
{
	FRotator currentBarrelRotation = barrel->GetForwardVector().Rotation();
	float deltaPitch = aimRotation.Pitch - currentBarrelRotation.Pitch;

	barrel->Pitch(deltaPitch);
}

void UTankAimComponent::MoveTurret(FRotator aimRotation)
{
	FRotator currentRotation = turret->GetForwardVector().Rotation();
	float deltaYaw = aimRotation.Yaw - currentRotation.Yaw;

	turret->Yaw(deltaYaw);
}

void UTankAimComponent::AimAt(FVector targetLocation)
{
	FString tankName = GetOwner()->GetName();
	Aim(targetLocation, tankName, launchSpeed);
}

void UTankAimComponent::Fire() //Called in blueprint
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
