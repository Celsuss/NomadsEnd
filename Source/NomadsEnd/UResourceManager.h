// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DataObjects/FResourceStruct.h"
#include "UResourceManager.generated.h"

UCLASS(Blueprintable)
class NOMADSEND_API UResourceManager : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TMap<EResourceEnum, FResourceStruct> ResourceMap;

public:
	UResourceManager();
	~UResourceManager();
};
