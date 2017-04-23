// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "FactoryBase.generated.h"

class ABuilding;
//
//UCLASS()
class NOMADSEND_API UFactoryBase
{
public:
	virtual ABuilding* CreateProductionBuilding(int id) = 0;
	virtual ABuilding* CreateGenerationBuilding(int id) = 0;
};
