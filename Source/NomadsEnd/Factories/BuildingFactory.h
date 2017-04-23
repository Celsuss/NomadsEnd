// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "FactoryBase.h"
#include "FStorageDataStruct.h"

class NOMADSEND_API UBuildingFactory : public UFactoryBase
{
	FStorageDataStruct* _data;
	UWorld* const _world;

public:
	UBuildingFactory(UWorld* world, FStorageDataStruct* const data);
	virtual ~UBuildingFactory();

	virtual ABuilding* CreateProductionBuilding(int id);
	virtual ABuilding* CreateGenerationBuilding(int id);
};
