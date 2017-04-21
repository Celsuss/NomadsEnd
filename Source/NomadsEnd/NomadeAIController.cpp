// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "NomadeAIController.h"
#include "AgentBase.h"

void ANomadeAIController::BeginPlay()
{
	Super::BeginPlay();

	m_Agent = (AAgentBase*)GetControlledPawn();
	if (!MoveToActor((AActor*)m_Agent->DesiredNode, 2.f))
		UE_LOG(LogTemp, Warning, TEXT("Failed to move"));
	UE_LOG(LogTemp, Warning, TEXT("Begin play"));
}

// Called every frame
void ANomadeAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}