// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



void UTankTrack::SetThrottle(float force, float relativeSpeed)
{

	FVector forceApplied = GetForwardVector() * relativeSpeed * force;
	FVector trackLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, trackLocation);
}
