// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BuildingFactory.h"
#include "ProductionBuilding.h"
#include "GenerationBuilding.h"

UBuildingFactory::UBuildingFactory(UWorld* world, FStorageDataStruct* const data) : _world(world){
	_data = data;
}

UBuildingFactory::~UBuildingFactory() {

}

ABuilding* UBuildingFactory::CreateProductionBuilding(int id)
{
	FTransform temp = FTransform(FRotator::ZeroRotator, FVector(0.f, 0.f, 300.f));
	auto newBuilding = Cast<AProductionBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AProductionBuilding::StaticClass(), temp));

	if (newBuilding != nullptr)
	{
		for (int i = 0; i < _data->Buildings.Num(); i++)
		{
			if (_data->Buildings[i].Id == id)
			{
				newBuilding->Init(&_data->Buildings[i]);
			}
		}
		UGameplayStatics::FinishSpawningActor(newBuilding, temp);
	}

	return newBuilding;
}

ABuilding* UBuildingFactory::CreateGenerationBuilding(int id)
{
	FTransform temp = FTransform(FRotator::ZeroRotator, FVector(0.f, 0.f, 300.f));
	auto newBuilding = Cast<AGenerationBuilding>(UGameplayStatics::BeginDeferredActorSpawnFromClass(_world, AGenerationBuilding::StaticClass(), temp));

	if (newBuilding != nullptr)
	{
		for (int i = 0; i < _data->Buildings.Num(); i++)
		{
			if (_data->Buildings[i].Id == id)
			{
				newBuilding->Init(&_data->Buildings[i]);
			}
		}
		UGameplayStatics::FinishSpawningActor(newBuilding, temp);
	}

	return newBuilding;
}