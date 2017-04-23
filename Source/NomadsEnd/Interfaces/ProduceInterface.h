// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//
#include "EResourceEnum.h"
#include "ProduceInterface.generated.h"

UINTERFACE(BlueprintType)
class NOMADSEND_API UProduceInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class NOMADSEND_API IProduceInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Building")
	bool ProduceResource(EResourceEnum resourceEnum, int count);
};