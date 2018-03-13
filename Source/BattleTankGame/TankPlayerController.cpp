// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine/World.h"
#include"DrawDebugHelpers.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	currentPawn = GetControlledTank()->GetName();
}

void ATankPlayerController::Tick(float deltatime)
{
	Super::Tick(deltatime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector hitLocation; //out parameter
	if (GetSightRayHitLocation(hitLocation)) //is going to line trace as side-effect
	{
		GetControlledTank()->AimAt(hitLocation);
	}
	// Get world location if linetrace through crosshair
	// return hit and aim at it
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{
	//Get screen coordinates of crosshair based on percentages
	int32 viewportSizeX, viewPortSizeY;
	GetViewportSize(viewportSizeX, viewPortSizeY); //out parameter
	FVector2D screenLocation { viewportSizeX*crossHairXLocation, viewPortSizeY*crossHairYLocation };

	//Deproject the crosshair position
	FVector worldDirection; //out
	GetLookDirection(screenLocation, worldDirection);

	//LineTrace
	if (GetLookVectorHit(worldDirection, hitLocation))
	{
		return true;
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHit(FVector& worldDirection, FVector& hitLocation) const
{
	FHitResult outHit;
	FVector lineTraceEnd = PlayerCameraManager->GetCameraLocation() + worldDirection * 200000.f;
	GetWorld()->LineTraceSingleByChannel(
		outHit,
		PlayerCameraManager->GetCameraLocation(),
		lineTraceEnd,
		ECollisionChannel::ECC_Visibility),
		FCollisionQueryParams(FName("IgnorePlayer"), false, GetControlledTank());

	if (outHit.GetActor()){ hitLocation = outHit.Location; return true; }
	return false;
}

void ATankPlayerController::GetLookDirection(FVector2D &screenLocation, FVector& worldDirection) const
{
	FVector cameraWorldLocation; //disregard
	DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection);
}

