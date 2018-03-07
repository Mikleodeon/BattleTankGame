// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	currentPawn = GetControlledTank()->GetName();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *currentPawn)
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Set tank AI Controller"))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



