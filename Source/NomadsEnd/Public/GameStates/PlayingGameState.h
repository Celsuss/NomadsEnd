// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameStateBase.h"

#include "PlayingGameState.generated.h"

/**
 * 
 */
UCLASS()
class NOMADSEND_API APlayingGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	/** World bounds for mini map & camera movement. */

	




	FBox WorldBounds;
};