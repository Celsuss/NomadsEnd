// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "PathNode.h"
#include "PathFollowerAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "BTTask_FindNextNode.h"

EBTNodeResult::Type UBTTask_FindNextNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	APathFollowerAIController* ai = Cast<APathFollowerAIController>(OwnerComp.GetAIOwner());
	if(!ai) return EBTNodeResult::Failed;

	APathNode* desiredNode = ai->GetDesiredNode();
	if (desiredNode){
		APathNode* nextNode = desiredNode->NextNode;
		if (nextNode) {
			ai->SetDesiredNode(nextNode);
			OwnerComp.GetBlackboardComponent()->SetValueAsObject(BlackboardKey.SelectedKeyName, nextNode);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}