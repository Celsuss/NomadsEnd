// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "PathFollowerAIController.h"
#include "AgentBase.h"
#include "PathNode.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

APathFollowerAIController::APathFollowerAIController(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	BehaviorComp = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	/* Match with the Blackboard */
	DesiredNodeKeyName = "DesiredNode";

	/* Initializes PlayerState so we can assign a team index to AI */
	bWantsPlayerState = true;
}

void APathFollowerAIController::BeginPlay()
{
	Super::BeginPlay();

	m_Agent = (AAgentBase*)GetPawn();
}

// Called every frame
void APathFollowerAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APathFollowerAIController::Possess(class APawn* InPawn)
{
	Super::Possess(InPawn);

	AAgentBase* agent = Cast<AAgentBase>(InPawn);
	if (agent)
	{
		DesiredNode = agent->DesiredNode;

		if (agent->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*agent->BehaviorTree->BlackboardAsset);

			BlackboardComp->SetValueAsObject(DesiredNodeKeyName, DesiredNode);
		}

		BehaviorComp->StartTree(*agent->BehaviorTree);
	}
}

void APathFollowerAIController::SetDesiredNode(APathNode* desiredNode) {
	DesiredNode = desiredNode;
}