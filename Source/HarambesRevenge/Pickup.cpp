// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "HarambesRevengeCharacter.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AddActorLocalRotation(FQuat(FVector::UpVector, 0.03f));
}

//void APickup::ReceiveHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
//{
//	if ((Other != NULL) && (Other != this))
//	{
//		AHarambesRevengeCharacter* harambe = Cast<AHarambesRevengeCharacter>(Other);
//		if (harambe) {
//			harambe->GainBanana();
//			Destroy();
//		}
//	}
//}


void APickup::NotifyActorBeginOverlap(AActor * OtherActor) {
	if ((OtherActor != NULL) && (OtherActor != this))
	{
		AHarambesRevengeCharacter* harambe = Cast<AHarambesRevengeCharacter>(OtherActor);
		if (harambe) {
			harambe->GainBanana();
			Destroy();
		}
		APickup* pickup = Cast<APickup>(OtherActor);
		if (pickup != NULL) {
			if(OtherActor->GetGameTimeSinceCreation() > GetGameTimeSinceCreation()){
				Destroy();
			}
			else {
				OtherActor->Destroy();
			}
		}
	}
}
