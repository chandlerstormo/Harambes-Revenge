// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "ZookeeperAIController.generated.h"

/**
 * 
 */
UCLASS()
class HARAMBESREVENGE_API AZookeeperAIController : public AAIController
{
	GENERATED_BODY()
	
private:
    void BeginPlay() override;
    void Tick(float deltaTime) override;
    void OnMoveCompleted(FAIRequestID id, EPathFollowingResult::Type result) override;
    
    enum State {
        Start,
        Chase,
        Attack,
        Dead
    };
    
    State CurrentState;
    void ChasePlayer();
    
protected:
    UPROPERTY(EditAnywhere)
    float Range = 800.0f;
	
	
};
