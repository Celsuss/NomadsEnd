// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//
#include "AIController.h"
#include "PathFollowerAIController.generated.h"

class AAgentBase;

///**
// * 
// */
UCLASS()
class NOMADSEND_API APathFollowerAIController : public AAIController
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

<<<<<<< HEAD:Source/NomadsEnd/NomadeAIController.h
	ABasicAI* m_AIActor;
};
=======
	AAgentBase* m_Agent;
	EPathFollowingStatus::Type m_DesiredMoveStatus;
};
>>>>>>> 57969ba29e0be10cd287caf5254491254a2144bb:Source/NomadsEnd/PathFollowerAIController.h
