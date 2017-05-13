// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ConstructingInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstructingInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
*
*/
class NOMADSEND_API IConstructingInterface
{
	GENERATED_IINTERFACE_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	bool IsConstructable();
};