// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FBuildingData.h"
#include "FStorageDataStruct.generated.h"

USTRUCT(BlueprintType)
struct NOMADSEND_API FStorageDataStruct : public FDataStructBase
{
	GENERATED_USTRUCT_BODY()

	//UPROPERTY(VisibleAnywhere, Category = "Data")
	TArray<FBuildingData*> Buildings;

public:
	FStorageDataStruct();
	~FStorageDataStruct();
};
