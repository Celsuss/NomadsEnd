// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//
#include "AIController.h"
#include "NomadeAIController.generated.h"

class ABasicAI;

///**
// * 
// */
UCLASS()
class NOMADSEND_API ANomadeAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ABasicAI* m_AIActor;
};
