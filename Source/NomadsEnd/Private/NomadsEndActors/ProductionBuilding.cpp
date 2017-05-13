// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "ProductionBuilding.h"

bool AProductionBuilding::ProduceResource_Implementation(EResourceEnum resourceEnum, int count) {
	return true;
}

bool AProductionBuilding::ConsumeResource_Implementation(EResourceEnum resourceEnum, int count) {
	return true;
}

void AProductionBuilding::Init(const FBuildingData& data)
{
	Super::Init(data);



}

void AProductionBuilding::BeginPlay()
{
	Super::BeginPlay();
}

//void AProductionBuilding::Init(FBuildingData* data)
//{
//
//}

//ProductionBuilding::~ProductionBuilding()
//{
//}
