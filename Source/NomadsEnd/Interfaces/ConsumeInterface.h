// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EResourceEnum.h"
#include "ConsumeInterface.generated.h"

UINTERFACE(BlueprintType)
class NOMADSEND_API UConsumeInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class NOMADSEND_API IConsumeInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Building")
	bool ConsumeResource(EResourceEnum resourceEnum, int count);
};