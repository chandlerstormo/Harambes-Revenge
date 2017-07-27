// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ZookeeperCharacter.generated.h"

UCLASS()
class HARAMBESREVENGE_API AZookeeperCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZookeeperCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
    void StartAttack();
    void StopAttack();
    
    float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
    void Die();
    void GiveDamage();
    
    FTimerHandle DeathTimer;
    FTimerHandle AttackTimer;
    
protected:
//    UPROPERTY(EditDefaultsOnly)
//        class UAnimMontage* AttackAnim;
    UPROPERTY(EditDefaultsOnly)
        class UAnimMontage* DeathAnim;
    UPROPERTY(EditAnywhere, Category = Damage)
        float ZookeeperDamage = 10.0f;
    UPROPERTY(EditAnywhere, Category = Damage)
        float ZookeeperHealth = 20.0f;
    UPROPERTY(EditAnywhere, Category = Weapon)
        TSubclassOf<class AWeapon> WeaponClass;
    
private:
    class AWeapon* MyWeapon;

};
