// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/SpawningInterface.h"
#include "Building.h"
#include "SpawnBuilding.generated.h"

UCLASS()
class NOMADSEND_API ASpawnBuilding : public ABuilding, public ISpawningInterface
{
	GENERATED_BODY()

public:
	//virtual bool ProduceResource_Implementation(EResourceEnum resourceEnum, int count) override;
	//virtual bool SPawnResource_Implementation(EResourceEnum resourceEnum, int count) override;

	virtual void Init(const FBuildingData& data) override;

protected:

	virtual void BeginPlay() override;
};
