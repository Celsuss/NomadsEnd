// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BuildingFactory.h"
#include "DataObjects/FStorageDataStruct.h"
#include "NomadsEndActors/ProductionBuilding.h"
//#include "NomadsEndActors/GenerationBuilding.h"
#include "NomadsEndActors/Building.h"


BuildingFactory::BuildingFactory(UWorld* world, FStorageDataStruct* data) : FactoryBase(world, data)
{
	
}

BuildingFactory::~BuildingFactory() {

}

FDataStructBase* BuildingFactory::GetActorInitializationData(uint64_t id)
{
	auto buildingData = (FStorageDataStruct*)_data;

	for (int i = 0; i < buildingData->Buildings.Num(); i++)
	{
		if (buildingData->Buildings[i]->Id == id)
		{
			return buildingData->Buildings[i];
		}
	}

	return 0;
}



AProductionBuilding* BuildingFactory::CreateProductionBuilding(uint64_t id, FTransform location) 
{
	auto newBuilding = Cast<AProductionBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AProductionBuilding::StaticClass(), location));
	auto data = GetActorInitializationData(id);
	newBuilding->Init(data);

	return (AProductionBuilding*)UGameplayStatics::FinishSpawningActor(newBuilding, location);
}