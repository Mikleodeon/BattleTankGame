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

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



