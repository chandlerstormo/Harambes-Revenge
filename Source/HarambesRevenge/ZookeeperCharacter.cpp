// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "HarambesRevengeCharacter.h"
#include "ZookeeperCharacter.h"
#include "ZookeeperAIController.h"
#include "Weapon.h"


// Sets default values
AZookeeperCharacter::AZookeeperCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    AIControllerClass = AZookeeperAIController::StaticClass();
    MyWeapon = nullptr;

}

// Called when the game starts or when spawned
void AZookeeperCharacter::BeginPlay()
{
	Super::BeginPlay();
    
    if (WeaponClass) {
        UWorld* World = GetWorld();
        if (World) {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Instigator = Instigator;
            FRotator Rotation(0.0f, 0.0f, -90.0f);
            MyWeapon = World->SpawnActor<AWeapon>(WeaponClass, FVector::ZeroVector, Rotation, SpawnParams);
            if (MyWeapon) {
                MyWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponPoint"));
            }
        }
    }
    MyWeapon->SetMyOwner(this);
}

// Called every frame
void AZookeeperCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AZookeeperCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AZookeeperCharacter::StartAttack() {
//    float duration = PlayAnimMontage(AttackAnim);
    
//    GetWorldTimerManager().SetTimer(AttackTimer, this, &ADwarf::GiveDamage, duration, true);
	if(this != nullptr && MyWeapon != nullptr)
	  MyWeapon->OnStartFire();
}

void AZookeeperCharacter::StopAttack() {
//    StopAnimMontage(AttackAnim);
	MyWeapon->OnStopFire();
    //GetWorldTimerManager().ClearTimer(AttackTimer);
}

void AZookeeperCharacter::Die() {
	MyWeapon->OnStopFire();
	MyWeapon->Destroy();
	
    Destroy();
}

void AZookeeperCharacter::GiveDamage() {
    AActor* player = UGameplayStatics::GetPlayerPawn(this, 0);
    player->TakeDamage(ZookeeperDamage, FDamageEvent(), GetInstigatorController(), this);
}

float AZookeeperCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) {
    float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
    if (ActualDamage > 0.0f) {
        ZookeeperHealth -= ActualDamage;
        if (ZookeeperHealth <= 0.0f) {
            // We're dead, don't allow further damage
            bCanBeDamaged = false;
            StopAttack();
			AActor* player = UGameplayStatics::GetPlayerPawn(this, 0);
			AHarambesRevengeCharacter* h = Cast<AHarambesRevengeCharacter>(player);
			h->onKill();
            float duration = PlayAnimMontage(DeathAnim);
            GetWorldTimerManager().SetTimer(DeathTimer, this, &AZookeeperCharacter::Die, duration - 0.25f, false);
            GetController()->UnPossess();
        }
    }
    return ActualDamage;
}