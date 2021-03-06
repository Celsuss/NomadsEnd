// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_LookForConstruction.generated.h"

/**
*
*/
UCLASS()
class NOMADSEND_API UBTService_LookForConstruction : public UBTService_BlackboardBase
{
	GENERATED_BODY()

		virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};