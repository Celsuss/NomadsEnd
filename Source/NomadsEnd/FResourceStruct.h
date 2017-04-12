// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EResourceEnum.h"
#include "FResourceStruct.generated.h"

USTRUCT()
struct NOMADSEND_API FResourceStruct
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	int32 Count;

	UPROPERTY()
	EResourceEnum ResourceType;

	FResourceStruct();
	~FResourceStruct();

	FResourceStruct(EResourceEnum resourceType, int32 count) 
	{
		ResourceType = resourceType;
		Count = count;
	}

	//bool operator== (const FResourceStruct& Other);
	//
	//friend uint8 GetTypeHash(const FResourceStruct& Other);
};
