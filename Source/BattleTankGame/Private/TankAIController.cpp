// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankAimComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	controlledTank = Cast<ATank>(GetPawn());
	playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	controlledTank->OnDeath.AddDynamic(this, &ATankAIController::OnTankDeath);
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move towards player tank
	MoveToActor(playerTank, acceptanceRadius);

	//Aim towards player tank
	controlledTank->tankAimComponent->Aim(playerTank->GetActorLocation());

	//Fire
	if (controlledTank->tankAimComponent->FiringStatus == EFiringStatus::Locked)
		controlledTank->tankAimComponent->Fire();
}

void ATankAIController::OnTankDeath()
{
	Destroy();
}







