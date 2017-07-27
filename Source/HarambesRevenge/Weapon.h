// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class HARAMBESREVENGE_API AWeapon : public AActor
{
	GENERATED_BODY()
    
protected:
    UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Weapon)
    USkeletalMeshComponent* WeaponMesh;
    UPROPERTY(EditDefaultsOnly, Category = Sound)
    class USoundCue* FireLoopSound;
    UPROPERTY(EditDefaultsOnly, Category = Sound)
    class USoundCue* FireFinishSound;
    UPROPERTY(Transient)
    class UAudioComponent* FireAC;
    UPROPERTY(EditDefaultsOnly, Category = Effects)
    class UParticleSystem* MuzzleFX;
    UPROPERTY(Transient)
    class UParticleSystemComponent* FireFX;
    UPROPERTY(EditAnywhere)
    float FireRate;
    UPROPERTY(EditAnywhere)
    float WeaponRange;
    UPROPERTY(EditDefaultsOnly)
    class UParticleSystem* HitEffect;
    UPROPERTY(EditAnywhere, Category = Damage)
    float WeaponDamage = 2.0f;
    
    class AZookeeperCharacter* MyOwner;
	
public:
	// Sets default values for this actor's properties
	AWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
    USkeletalMeshComponent* GetWeaponMesh();
    
    void OnStartFire();
    void OnStopFire();
    
    UAudioComponent* PlayWeaponSound(class USoundCue*);
    
    void SetMyOwner(class AZookeeperCharacter*);
    class AZookeeperCharacter* GetMyOwner() { return MyOwner; }
    
    FTimerHandle WeaponTimer;
    
    void WeaponTrace();

	
	
};
