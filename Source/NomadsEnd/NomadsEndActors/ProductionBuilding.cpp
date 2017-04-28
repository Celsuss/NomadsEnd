// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "ProductionBuilding.h"



bool AProductionBuilding::ProduceResource_Implementation(EResourceEnum resourceEnum, int count) {
	return true;
}

bool AProductionBuilding::ConsumeResource_Implementation(EResourceEnum resourceEnum, int count) {
	return true;
}

void AProductionBuilding::Init(FDataStructBase* data)
{
	auto buildingData = (FBuildingData*)data;
}

//AProductionBuilding::AProductionBuilding(const FObjectInitializer& ObjectInitializer)
//	: Super(ObjectInitializer)
//{
//
//}

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
