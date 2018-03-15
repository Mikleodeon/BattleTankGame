// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::IntendMoveForward(float relativeSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("intend move forward %f"), relativeSpeed);
}

void UTankMovementComponent::SetTrackReference(UTankTrack* leftTrackToSet, UTankTrack* rightTrackToSet)
{
	leftTrack = leftTrackToSet;
	rightTrack = rightTrackToSet;
}