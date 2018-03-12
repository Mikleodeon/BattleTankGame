// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	currentPawn = GetControlledTank()->GetName();
	playerTank = GetPlayerTank()->GetName();

	if (GetControlledTank()){UE_LOG(LogTemp, Warning, TEXT("AI tank: %s"), *currentPawn)}
	else {UE_LOG(LogTemp, Warning, TEXT("Set tank AI Controller"))}

	if (GetPlayerTank()) { UE_LOG(LogTemp, Warning, TEXT("Found player: %s"), *playerTank) }
	else { UE_LOG(LogTemp, Warning, TEXT("Can't find player tank")) }


	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerLocation());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

FVector ATankAIController::GetPlayerLocation()
{
	return GetPlayerTank()->GetActorLocation();
}





