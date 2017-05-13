// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BTService_LookForConstruction.h"

void UBTService_LookForConstruction::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	GetWorld()->GetGameState();
}