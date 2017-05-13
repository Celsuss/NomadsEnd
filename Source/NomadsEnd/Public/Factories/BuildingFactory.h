// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FactoryBase.h"

class ABuilding;
class AProductionBuilding;
class AGenerationBuilding;
class ASpawnBuilding;
struct FStorageDataStruct;

class NOMADSEND_API BuildingFactory : public FactoryBase
{
	AProductionBuilding* CreateProductionBuilding(const FBuildingData& data, FTransform location);
	AGenerationBuilding* CreateGenerationBuilding(const FBuildingData& data, FTransform location);
	ASpawnBuilding* CreateSpawnBuilding(const FBuildingData& data, FTransform location);

	FDataStructBase* GetActorInitializationData(uint64_t id) override;

public:
	BuildingFactory(UWorld* world, const FStorageDataStruct& data);

	~BuildingFactory();

	ABuilding* CreateBuilding(uint64_t id, FTransform location);	
};
