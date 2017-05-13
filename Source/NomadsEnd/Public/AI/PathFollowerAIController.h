// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//
#include "AIController.h"
#include "PathFollowerAIController.generated.h"

class APathNode;
class AAgentBase;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class NOMADSEND_API APathFollowerAIController : public AAIController
{
	GENERATED_BODY()

	APathFollowerAIController(const class FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/* Called whenever the controller possesses a character bot */
	virtual void Possess(class APawn* InPawn) override;

	AAgentBase* m_Agent;
	EPathFollowingStatus::Type m_DesiredMoveStatus;

	UBehaviorTreeComponent* BehaviorComp;
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName DesiredNodeKeyName;

	UPROPERTY(EditAnywhere, Category = "AI")
	class APathNode* DesiredNode;

public:
	void SetDesiredNode(APathNode* desiredNode);

	/** Returns BehaviorComp subobject **/
	FORCEINLINE UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	FORCEINLINE APathNode* GetDesiredNode() const { return DesiredNode; }
};