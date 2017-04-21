// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "PathFollowerAIController.h"
#include "AgentBase.h"
#include "PathNode.h"

void APathFollowerAIController::BeginPlay()
{
	Super::BeginPlay();

	m_Agent = (AAgentBase*)GetPawn();
	MoveToActor((AActor*)(m_Agent->DesiredNode), 2.f);
	m_DesiredMoveStatus = EPathFollowingStatus::Moving;
}

// Called every frame
void APathFollowerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetMoveStatus() != m_DesiredMoveStatus) {
		m_Agent->DesiredNode = m_Agent->DesiredNode->NextNode;
		MoveToActor((AActor*)(m_Agent->DesiredNode), 2.f);
	}
}