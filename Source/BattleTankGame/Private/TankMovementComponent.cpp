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
	FVector CurrentDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	FVector EndDirection = MoveVelocity.GetSafeNormal();
	float AILocSpeed = FVector::DotProduct(CurrentDirection, EndDirection);
	auto AIRotSpeed = FVector::CrossProduct(CurrentDirection, EndDirection);
	IntendMoveForward(AILocSpeed);
	IntendMoveRight(AIRotSpeed.Z);
}


void UTankMovementComponent::IntendMoveForward(float relativeSpeed)
{
	leftTrack->SetThrottle(relativeSpeed);
	rightTrack->SetThrottle(relativeSpeed);
}

void UTankMovementComponent::IntendMoveRight(float relativeSpeed)
{
	leftTrack->SetThrottle(relativeSpeed);
	rightTrack->SetThrottle(relativeSpeed*-1.f);
}