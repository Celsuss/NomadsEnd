// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindNextNode.generated.h"

/**
 * 
 */
UCLASS()
class NOMADSEND_API UBTTask_FindNextNode : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
		/** starts this task, should return Succeeded, Failed or InProgress
		*  (use FinishLatentTask() when returning InProgress)
		* this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};