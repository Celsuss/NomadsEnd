// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FactoryBase.h"

class ABuilding;
class AProductionBuilding;
struct FStorageDataStruct;

class NOMADSEND_API BuildingFactory : public FactoryBase
{
public:
	BuildingFactory(UWorld* world, FStorageDataStruct* data);

	~BuildingFactory();

	FDataStructBase* GetActorInitializationData(uint64_t id) override;

	AProductionBuilding* CreateProductionBuilding(uint64_t id, const FVector& pos);
};
