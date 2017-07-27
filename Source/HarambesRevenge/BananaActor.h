// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BananaActor.generated.h"

UCLASS()
class HARAMBESREVENGE_API ABananaActor : public AActor
{
	GENERATED_BODY()

		/** Capsule collision component */
		//UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		//class UCapsuleComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* ProjectileMovement;

public:
	ABananaActor();

	/** called when projectile hits something */
	

	/** Returns CollisionComp subobject **/
	//FORCEINLINE class UCapsuleComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE class UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
protected:

	UPROPERTY(EditAnywhere, Category = Damage)
		float Damage = 2.0f;
private:
	
};
