// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = Cast<ATank>(GetPawn());
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move towards player tank
	MoveToActor(playerTank, acceptanceRadius);

	//Aim towards player tank
	controlledTank->AimAt(playerTank->GetActorLocation());

	//Fire
	controlledTank->Fire();
}







