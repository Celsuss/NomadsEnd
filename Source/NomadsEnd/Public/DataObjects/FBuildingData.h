// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FResourceStruct.h"
#include "FDataStructBase.h"
#include "FBuildingData.generated.h"

USTRUCT(BlueprintType)
struct NOMADSEND_API FBuildingData : public FDataStructBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FResourceStruct> CostToBuild;

	UPROPERTY(EditAnywhere)
	float TimeToBuild;

	UPROPERTY(EditAnywhere)
	FString StaticMeshPath;

	UPROPERTY(EditAnywhere)
	EBuildingType BuildingType;

	FBuildingData();
	~FBuildingData();
};
