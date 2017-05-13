// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/ProduceInterface.h"
#include "Interfaces/ConsumeInterface.h"
#include "Building.h"
#include "ProductionBuilding.generated.h"


UCLASS()
class NOMADSEND_API AProductionBuilding : public ABuilding, public IProduceInterface, public IConsumeInterface
{
	GENERATED_BODY()

public:

	virtual bool ProduceResource_Implementation(EResourceEnum resourceEnum, int count) override;
	virtual bool ConsumeResource_Implementation(EResourceEnum resourceEnum, int count) override;
	
	virtual void Init(const FBuildingData& data) override;
	
protected:

	virtual void BeginPlay() override;
};