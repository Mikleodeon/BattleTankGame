// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class URadialForceComponent;
class UParticleSystemComponent;
class UBulletMovement;
UCLASS()
class BATTLETANKGAME_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void launchProjectile(float speed);



private:

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UBulletMovement * bulletMovement;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
		UStaticMeshComponent* CollisionMesh;

	UPROPERTY(VisibleAnywhere, Category = Particles)
		UParticleSystemComponent* LaunchBlast;

	UPROPERTY(VisibleAnywhere, Category = Particles)
		UParticleSystemComponent* ImpactBlast;

	UPROPERTY(VisibleAnywhere, Category = Particles)
		URadialForceComponent* ExplosionForce;

	UPROPERTY(EditDefaultsOnly, Category = Damage)
		float ProjectileDmg = 20.f;

};
