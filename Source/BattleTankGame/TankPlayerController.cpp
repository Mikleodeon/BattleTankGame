// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin")); 
	currentPawn = GetControlledTank()->GetName();
	if (*currentPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *currentPawn);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Pawn"));
	}
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
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *hitLocation.ToString());
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
	GetLookVectorHit(worldDirection, hitLocation);
	return true;

}

bool ATankPlayerController::GetLookVectorHit(FVector& worldDirection, FVector& hitLocation) const
{
	FHitResult outHit;
	FVector lineTraceEnd = PlayerCameraManager->GetCameraLocation() + worldDirection * 1000000.f;
	GetWorld()->LineTraceSingleByChannel(
		outHit,
		PlayerCameraManager->GetCameraLocation(),
		lineTraceEnd,
		ECollisionChannel::ECC_Visibility);

	if (outHit.GetActor() != GetControlledTank()) { hitLocation = outHit.Location; return true;}
	else { hitLocation = { 0.f, 0.f, 0.f };  return false; }
}

void ATankPlayerController::GetLookDirection(FVector2D &screenLocation, FVector& worldDirection) const
{
	FVector cameraWorldLocation; //disregard
	DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, worldDirection);
}

