// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "AI/PathFollowerAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "BTTask_SetRandomWalkableLocation.h"

EBTNodeResult::Type UBTTask_SetRandomWalkableLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	APathFollowerAIController* ai = Cast<APathFollowerAIController>(OwnerComp.GetAIOwner());
	if (!ai) return EBTNodeResult::Failed;

	GetWorld()->GetGameState();
	
	UNavigationSystem* navSys = UNavigationSystem::GetCurrent(ai->GetPawn());
	if (navSys){
		const float SearchRadius = 1000.0f;
		FNavLocation RandomPt;
		const bool bFound = navSys->GetRandomPointInNavigableRadius(ai->GetPawn()->GetActorLocation(), SearchRadius, RandomPt);
		if (bFound){
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), RandomPt.Location);
			//OwnerComp.GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, RandomPt.Location);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}