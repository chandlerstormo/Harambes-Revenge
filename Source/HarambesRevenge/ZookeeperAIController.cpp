// Fill out your copyright notice in the Description page of Project Settings.

#include "HarambesRevenge.h"
#include "ZookeeperAIController.h"
#include "ZookeeperCharacter.h"


void AZookeeperAIController::BeginPlay() {
    Super::BeginPlay();
    CurrentState = Start;
}

void AZookeeperAIController::Tick(float deltaTime) {
    Super::Tick(deltaTime);
    if (CurrentState == Start)
    {
        //ChasePlayer();
        CurrentState = Chase;
    }
    if (CurrentState == Attack) {
        if (GetPawn() != nullptr) {
            FVector zookeeperPos = GetPawn()->GetActorLocation();
            AActor* actor = UGameplayStatics::GetPlayerPawn(this, 0);
            FVector actorPos = actor->GetActorLocation();
            
            MoveToActor(actor, 800.0f);
            FVector vec = actorPos - zookeeperPos;
            vec.Normalize();
            FRotator rot = vec.Rotation();
            GetPawn()->SetActorRotation(rot);
            
            float distance = FVector::Dist(actorPos, zookeeperPos);
            if (distance > Range) {
                //ChasePlayer();
                CurrentState = Chase;
                Cast<AZookeeperCharacter>(GetPawn())->StopAttack();
            }
        }
    }
    if (CurrentState == Chase) {
        AActor* actor = UGameplayStatics::GetPlayerPawn(this, 0);
        FVector actorPos = actor->GetActorLocation();
        if (GetPawn() != nullptr) {
			FVector zookeeperPos = GetPawn()->GetActorLocation();
			float distance = FVector::Dist(actorPos, zookeeperPos);
			if (distance > Range) {
				//ChasePlayer();
                
                //FVector range(1.0f, 1.0f, 1.0f);
                
                
//                MoveToLocation(vec*.005f);
                CurrentState = Chase;
                //Cast<AZookeeperCharacter>(GetPawn())->StopAttack();
            
                
				MoveToActor(actor, 800.0f);
                FVector vec = actorPos - zookeeperPos;
                vec.Normalize();
                FRotator rot = vec.Rotation();
                GetPawn()->SetActorRotation(rot);
                
                
                //FVector range(10.0f, 10.0f, 10.0f);
                //MoveToLocation(actorPos+range);
				//MoveToLocation(FVector(actor->GetActorLocation().X,0, actor->GetActorLocation().Z));
                
			}
			else
			{
				CurrentState = Attack;
				Cast<AZookeeperCharacter>(GetPawn())->StartAttack();
			}
		}
	}

}

//void AZookeeperAIController::ChasePlayer() {
//	//FVector zookeeperPos = GetPawn()->GetActorLocation();
//    AActor* actor = UGameplayStatics::GetPlayerPawn(this, 0);
//    FVector actorPos = actor->GetActorLocation();
//    FVector zookeeperPos = GetPawn()->GetActorLocation();
//    
//	//FVector harambePos = position->GetActorLocation();
//	//FVector targetPos = FVector(harambePos.X, zookeeperPos.Y, harambePos.Z);
//    MoveToActor(actor, 800.0f);
//    
//    //FVector range(1.0f, 1.0f, 1.0f);
//    
//    FVector vec = actorPos - zookeeperPos;
//    vec.Normalize();
//    FRotator rot = vec.Rotation();
//    GetPawn()->SetActorRotation(rot);
////
//}

void AZookeeperAIController::OnMoveCompleted(FAIRequestID id, EPathFollowingResult::Type result) {
    if (result == EPathFollowingResult::Success && CurrentState != Attack) {
        CurrentState = Attack;
        Cast<AZookeeperCharacter>(GetPawn())->StartAttack();
    }
}