// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BuildingFactory.h"
#include "DataObjects/FStorageDataStruct.h"
#include "NomadsEndActors/Building.h"
#include "NomadsEndActors/ProductionBuilding.h"
#include "NomadsEndActors/GenerationBuilding.h"
#include "NomadsEndActors/SpawnBuilding.h"

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
//
//template <typename T>
//TSubclassOf<ABuilding>* BuildingFactory::CreateBuilding(uint64_t id, FTransform location)
//{
//	auto newBuilding = Cast<T>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, T::StaticClass(), location));
//	auto data = (FBuildingData*)GetActorInitializationData(id);
//	newBuilding->Init(data);
//
//	return Cast<T>(UGameplayStatics::FinishSpawningActor(newBuilding, location));
//}

ABuilding* BuildingFactory::CreateBuilding(uint64_t id, FTransform location)
{
	ABuilding* newBuilding;
	auto data = (FBuildingData*)GetActorInitializationData(id);

	switch (data->BuildingType)
	{
		case EBuildingType::BT_ProductionBuilding:
			newBuilding = CreateProductionBuilding(*data, location);
			break;
		case EBuildingType::BT_GenerationBuilding:
			newBuilding = CreateGenerationBuilding(*data, location);
			break;
		case EBuildingType::BT_SpawnBuilding:
			newBuilding = CreateSpawnBuilding(*data, location);
			break;
		default:
			newBuilding = nullptr;
			UE_LOG(NomadsEndLog, Warning, TEXT("Building failed to create!"))
			break;
	}

	if(newBuilding != nullptr)
		return Cast<ABuilding>(UGameplayStatics::FinishSpawningActor(newBuilding, location));

	return nullptr;
}

AProductionBuilding* BuildingFactory::CreateProductionBuilding(const FBuildingData& data, FTransform location) 
{
	auto newBuilding = Cast<AProductionBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AProductionBuilding::StaticClass(), location));
	newBuilding->Init(data);

	return Cast<AProductionBuilding>(UGameplayStatics::FinishSpawningActor(newBuilding, location));
}

AGenerationBuilding* BuildingFactory::CreateGenerationBuilding(const FBuildingData& data, FTransform location)
{
	auto newBuilding = Cast<AGenerationBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AGenerationBuilding::StaticClass(), location));
	newBuilding->Init(data);

	return Cast<AGenerationBuilding>(UGameplayStatics::FinishSpawningActor(newBuilding, location));
}

ASpawnBuilding* BuildingFactory::CreateSpawnBuilding(const FBuildingData& data, FTransform location)
{
	auto newBuilding = Cast<ASpawnBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, ASpawnBuilding::StaticClass(), location));
	newBuilding->Init(data);

	return Cast<ASpawnBuilding>(UGameplayStatics::FinishSpawningActor(newBuilding, location));
}