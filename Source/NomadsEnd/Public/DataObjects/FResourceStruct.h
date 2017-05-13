// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EResourceEnum.h"
#include "FResourceStruct.generated.h"

USTRUCT(BlueprintType)
struct NOMADSEND_API FResourceStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
	int32 Count;

	UPROPERTY()
	EResourceEnum ResourceType;

public:
	FResourceStruct();
	~FResourceStruct();

	FResourceStruct(EResourceEnum resourceType, int32 count) 
	{
		ResourceType = resourceType;
		Count = count;
	}
};
