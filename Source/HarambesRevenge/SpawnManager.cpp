// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "SpawnManager.h"
#include "Engine/TargetPoint.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle mSpawnTime;
	GetWorldTimerManager().SetTimer(mSpawnTime, this, &ASpawnManager::OnSpawnTimer, SpawnTime, false);
}

// Called every frame
void ASpawnManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}
void ASpawnManager::OnSpawnTimer() {
	int num = SpawnPoints.Num();
	int index = FMath::RandRange(0, num - 1);
	ATargetPoint* a = SpawnPoints[index];
	FVector pos = a->GetActorLocation();
	FRotator rot = a->GetActorRotation();
	ACharacter* Char = GetWorld()->SpawnActor<ACharacter>(CharacterClass, pos, rot);
	SpawnTime *= SpawnTimeSpeedupPerSpawn;
	if (SpawnTime < 0.1f) SpawnTime = 0.1f;
	if (Char)
	{
		// Spawn the AI controller for the character
		Char->SpawnDefaultController();
	}
    
    AActor* actor = GetWorld()->SpawnActor<AActor>(ActorClass, pos, rot);

	FTimerHandle mSpawnTime;
	GetWorldTimerManager().SetTimer(mSpawnTime, this, &ASpawnManager::OnSpawnTimer, SpawnTime, false);
}

