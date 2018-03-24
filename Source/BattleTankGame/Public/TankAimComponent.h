// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKGAME_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetComponentReferences(UTankBarrel* barrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Fire)
		void Fire();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = "Status")
		EFiringStatus FiringStatus = EFiringStatus::Aiming;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> Projectile_BP;

public:	

	void Aim(FVector targetLocation);

private:
	UTankBarrel* barrel;
	UTankTurret* turret;

	void MoveBarrel(FRotator);

	void MoveTurret(FRotator);

	bool IsBarrelMove();
	
	//Variables accessable by BP
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float launchSpeed = 10000; //TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float reloadTime = 3;

	float lastFireTime = 0;

	FVector aimDirection;


};
