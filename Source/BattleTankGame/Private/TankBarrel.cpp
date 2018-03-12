// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Pitch(float deltaPitch)
{
	float relativeSpeed_Clamp = FMath::Clamp(deltaPitch, -1.f, 1.f);

	float pitchChange = deltaPitch * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newPitch = RelativeRotation.Pitch + pitchChange; //end pitch per frame
	float newPitch_Clamp = FMath::Clamp(newPitch, minElevation, maxElevation); //clamped end pitch

	SetRelativeRotation(FRotator(newPitch_Clamp, 0.f, 0.f));
}
