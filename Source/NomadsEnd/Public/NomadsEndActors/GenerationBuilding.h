// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/ProduceInterface.h"
#include "Building.h"
#include "GenerationBuilding.generated.h"

UCLASS()
class NOMADSEND_API AGenerationBuilding : public ABuilding, public IProduceInterface
{
	GENERATED_BODY()
public:
	virtual bool ProduceResource_Implementation(EResourceEnum resourceEnum, int count) override;

	virtual void Init(const FBuildingData& data) override;

protected:

	virtual void BeginPlay() override;
};
