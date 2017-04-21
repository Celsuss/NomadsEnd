// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "FBuildingData.h"


FBuildingData::FBuildingData()
{
	Name = FName(TEXT("ByggarData"));
	TimeToBuild = 1.f;
	CostToBuild.Add(FResourceStruct((EResourceEnum)1, 10));
	CostToBuild.Add(FResourceStruct((EResourceEnum)2, 100));
}

FBuildingData::~FBuildingData()
{
}
