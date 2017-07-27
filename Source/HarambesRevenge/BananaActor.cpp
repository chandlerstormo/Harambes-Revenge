// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "BananaActor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ZookeeperCharacter.h"

// Sets default values
ABananaActor::ABananaActor()
{
	// Use a sphere as a simple collision representation
	//CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	//CollisionComp->InitCapsuleSize(5.0f, 5.0f);
	//CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	//CollisionComp->OnComponentHit.AddDynamic(this, &ABananaActor::OnHit);		// set up a notification for when this component hits something blocking

	//																					// Players can't walk on it
	//CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	//CollisionComp->CanCharacterStepUpOn = ECB_No;

	//// Set as root component
	//RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	//ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	
	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ABananaActor::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//this isn't actually working
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		AZookeeperCharacter* zk = Cast<AZookeeperCharacter>(Hit.GetActor());
		if (zk) {
			zk->TakeDamage(Damage, FDamageEvent(), GetInstigatorController(), this);
		}
		//Destroy();
	}
	AZookeeperCharacter* zk = Cast<AZookeeperCharacter>(Hit.GetActor());
	if (zk) {
		zk->TakeDamage(Damage, FDamageEvent(), GetInstigatorController(), this);
		
	}
}
