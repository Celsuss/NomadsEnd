// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "NomadsEndGameModeBase.generated.h"

class UGameDataRepository;

UCLASS()
class NOMADSEND_API ANomadsEndGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	ANomadsEndGameModeBase();

	UGameDataRepository* Repository;

	virtual void StartPlay() override;
	
};
