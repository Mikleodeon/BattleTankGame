// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::Yaw(float deltaYaw)
{
	float relativeSpeed = FMath::Clamp(deltaYaw, -1.f, 1.f); //normalized
	float yawChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newYaw = RelativeRotation.Yaw + yawChange;
	SetRelativeRotation(FRotator(0.f, newYaw, 0.f));
	
}



