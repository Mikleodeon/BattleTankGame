// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//Calculate slipping speed
	auto SlipSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	//Work out the required acceleration this frame to correct
	auto CorrectiveAcceleration = -SlipSpeed / DeltaTime * GetRightVector();
	//calculate and apply sideways force f=m*a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectiveAcceleration) /2 ; //Two tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float relativeSpeed)
{

	FVector forceApplied = GetForwardVector() * relativeSpeed * forceNewtons;
	FVector trackLocation = GetComponentLocation();
	auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, trackLocation);
}
