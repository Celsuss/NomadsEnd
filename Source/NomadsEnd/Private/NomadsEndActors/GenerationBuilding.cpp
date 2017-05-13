// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "GenerationBuilding.h"

//AGenerationBuilding::AGenerationBuilding()
//{
//}
//
//AGenerationBuilding::~AGenerationBuilding()
//{
//}

bool AGenerationBuilding::ProduceResource_Implementation(EResourceEnum resourceEnum, int count)
{
	return true;
}

void AGenerationBuilding::Init(const FBuildingData& data)
{
	Super::Init(data);



}

void AGenerationBuilding::BeginPlay()
{
	Super::BeginPlay();
}
