// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DataObjects/EResourceEnum.h"
#include "SpawningInterface.generated.h"

UINTERFACE(BlueprintType)
class NOMADSEND_API USpawningInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class NOMADSEND_API ISpawningInterface
{
	GENERATED_IINTERFACE_BODY()

//public:
//	UFUNCTION(BlueprintNativeEvent, Category = "Building")
//		bool ProduceResource(EResourceEnum resourceEnum, int count);
};