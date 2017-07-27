// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

UCLASS()
class HARAMBESREVENGE_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:
	UPROPERTY(EditAnywhere)
		TArray<class ATargetPoint*> SpawnPoints;
	UPROPERTY(EditAnywhere)
		TSubclassOf<ACharacter> CharacterClass;
    UPROPERTY(EditAnywhere)
        TSubclassOf<AActor> ActorClass;
	UPROPERTY(EditAnywhere)
		float SpawnTime = 10.0f;
	UPROPERTY(EditAnywhere )
		float SpawnTimeSpeedupPerSpawn = 0.5f;
	void OnSpawnTimer();
	
	
};
