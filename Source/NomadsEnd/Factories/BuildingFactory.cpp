// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BuildingFactory.h"
#include "DataObjects/FStorageDataStruct.h"
#include "NomadsEndActors/ProductionBuilding.h"
//#include "NomadsEndActors/GenerationBuilding.h"
#include "NomadsEndActors/Building.h"


BuildingFactory::BuildingFactory(UWorld* world, const FStorageDataStruct& data) : FactoryBase(world, data)
{
}

BuildingFactory::~BuildingFactory() 
{
}

FDataStructBase* BuildingFactory::GetActorInitializationData(uint64_t id)
{
	for (int i = 0; i < _data->Buildings.Num(); i++)
	{
		if (_data->Buildings[i].Id == id)
		{
			return (FDataStructBase*)&(_data->Buildings[i]);
		}
	}

	return 0;
}



AProductionBuilding* BuildingFactory::CreateProductionBuilding(uint64_t id, FTransform location) 
{
	auto newBuilding = Cast<AProductionBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AProductionBuilding::StaticClass(), location));
	auto data = (FBuildingData*)GetActorInitializationData(id);
	newBuilding->Init(data);

	return Cast<AProductionBuilding>(UGameplayStatics::FinishSpawningActor(newBuilding, location));
}