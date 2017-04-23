// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FDtoBase.h"
#include "FResourceStruct.h"
#include "FBuildingData.generated.h"

USTRUCT(BlueprintType)
struct NOMADSEND_API FBuildingData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
	int Id;

	UPROPERTY(VisibleAnywhere)
	FName Name;

	UPROPERTY(EditAnywhere)
	TArray<FResourceStruct> CostToBuild;

	UPROPERTY(EditAnywhere)
	float TimeToBuild;

	FBuildingData();
	~FBuildingData();

	bool FBuildingData::operator==(const FBuildingData &other) const
	{
		return Id == other.Id;
	};
};
