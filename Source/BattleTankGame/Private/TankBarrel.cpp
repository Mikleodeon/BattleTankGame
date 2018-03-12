// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"




void UTankBarrel::Pitch(float relativeSpeed)
{
	float relativeSpeed_Clamp = FMath::Clamp((int)relativeSpeed, -1, 1);

	float pitchChange = relativeSpeed * maxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float newPitch = RelativeRotation.Pitch + pitchChange;
	float newPitch_Clamp = FMath::Clamp(newPitch, minElevation, maxElevation);
	//UE_LOG(LogTemp, Warning, TEXT("%f"), relativeSpeed);
	UE_LOG(LogTemp, Warning, TEXT("%f"), relativeSpeed_Clamp);

	SetRelativeRotation(FRotator(newPitch_Clamp, 0.f, 0.f));
}
