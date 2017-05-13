// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameStateBase.h"
#include "PlayingGameState.generated.h"

class ABuilding;

UCLASS()
class NOMADSEND_API APlayingGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	void AddConstructionBuilding(ABuilding* building);
	ABuilding* GetConstructionBuilding();

	FBox WorldBounds;
	TArray<ABuilding*> ConstructionArray;
};