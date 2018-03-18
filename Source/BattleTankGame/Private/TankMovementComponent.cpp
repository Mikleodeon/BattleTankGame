// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::SetTrackReference(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet)
{
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *MoveVelocity.ToString());
}


void UTankMovementComponent::IntendMoveForward(float relativeSpeed)
{
	leftTrack->SetThrottle(relativeSpeed);
	rightTrack->SetThrottle(relativeSpeed);
}

void UTankMovementComponent::IntendMoveLeft(float relativeSpeed)
{
	leftTrack->SetThrottle(relativeSpeed);
	rightTrack->SetThrottle(relativeSpeed *-1.f);
}

void UTankMovementComponent::IntendMoveRight(float relativeSpeed)
{
	leftTrack->SetThrottle(relativeSpeed);
	rightTrack->SetThrottle(relativeSpeed*-1.f);
}