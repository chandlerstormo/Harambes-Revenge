// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "Weapon.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "ZookeeperCharacter.h"
#include "HarambesRevengeCharacter.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
    RootComponent = WeaponMesh;
    FireRate = 0.1f;
    WeaponRange = 10000.0f;

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

USkeletalMeshComponent* AWeapon::GetWeaponMesh() {
    return WeaponMesh;
}

UAudioComponent* AWeapon::PlayWeaponSound(USoundCue* Sound) {
    UAudioComponent* AC = NULL;
    if (Sound)
    {
        AC = UGameplayStatics::SpawnSoundAttached(Sound, RootComponent);
    }
    return AC;
}

void AWeapon::OnStartFire() {
	if (FireAC != nullptr) {
		FireAC->Stop();
	}

    FireAC = PlayWeaponSound(FireLoopSound);
    
    FireFX = UGameplayStatics::SpawnEmitterAttached(MuzzleFX, WeaponMesh, TEXT("MuzzleFlashSocket"));
    
    GetWorldTimerManager().SetTimer(WeaponTimer, this, &AWeapon::WeaponTrace, FireRate, true);
}

void AWeapon::OnStopFire() {
    if (FireAC != nullptr) {
        FireAC->Stop();
    }
    if (FireFinishSound != nullptr) {
        PlayWeaponSound(FireFinishSound);
    }
    
    if (FireFX != nullptr) {
        FireFX->DeactivateSystem();
    }
    
    GetWorldTimerManager().ClearTimer(WeaponTimer);
}

void AWeapon::SetMyOwner(AZookeeperCharacter* character) {
    MyOwner = character;
}

void AWeapon::WeaponTrace() {
    static FName WeaponFireTag = FName(TEXT("WeaponTrace"));
    static FName MuzzleSocket = FName(TEXT("MuzzleFlashSocket"));
    
    // Start from the muzzle's position
    FVector StartPos = WeaponMesh->GetSocketLocation(MuzzleSocket);
    // Get forward vector of MyPawn
    FVector Forward = MyOwner->GetActorForwardVector();
    // Calculate end position
    FVector EndPos = Forward*WeaponRange - StartPos;
    
    // Perform trace to retrieve hit info
    FCollisionQueryParams TraceParams(WeaponFireTag, true, Instigator);
    TraceParams.bTraceAsyncScene = true;
    TraceParams.bReturnPhysicalMaterial = true;
    
    // This fires the ray and checks against all objects w/ collision
    FHitResult Hit(ForceInit);
    GetWorld()->LineTraceSingleByObjectType(Hit, StartPos, EndPos, FCollisionObjectQueryParams::AllObjects, TraceParams);
    // Did this hit anything?
    if (Hit.bBlockingHit)
    {
        UGameplayStatics::SpawnEmitterAtLocation(this, HitEffect, Hit.ImpactPoint);
        AHarambesRevengeCharacter* harambe = Cast<AHarambesRevengeCharacter>(Hit.GetActor());
        if (harambe)
        {
            harambe->TakeDamage(WeaponDamage, FDamageEvent(), GetInstigatorController(), this);
        }
    }
    
}