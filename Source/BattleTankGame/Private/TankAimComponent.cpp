// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



void UTankAimComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet)
{
	barrel = barrelToSet;
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

	// ...
}

void UTankAimComponent::Aim(FVector hitLocation, FString& tankName, float launchSpeed)
{
	if (!barrel) { return; }

	FVector outLaunchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("endBarrel"));

	//Calculate the outLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity(this, outLaunchVelocity, startLocation, hitLocation, launchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector aimDirection = outLaunchVelocity.GetSafeNormal();
		
		MoveBarrel(aimDirection.Rotation());
	}
}

void UTankAimComponent::MoveBarrel(FRotator aimRotation)
{
	FRotator barrelRotation = barrel->GetForwardVector().Rotation();
	FRotator deltaRotation = aimRotation - barrelRotation;
}
