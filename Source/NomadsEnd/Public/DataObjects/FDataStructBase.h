// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FDataStructBase.generated.h"

USTRUCT()
struct NOMADSEND_API FDataStructBase
{
public:
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
	int Id;

	UPROPERTY(VisibleAnywhere)
	FName Name;

	FDataStructBase();
	virtual ~FDataStructBase();

	bool FDataStructBase::operator==(const FDataStructBase &other) const
	{
		return Id == other.Id;
	};
};
