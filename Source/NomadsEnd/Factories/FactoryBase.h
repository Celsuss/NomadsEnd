// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <stdint.h>

#include "NomadsEndActors/NomadsEndBaseActor.h"
#include "DataObjects/FDataStructBase.h"

class NOMADSEND_API FactoryBase
{
protected:
	UWorld* const _world;
	FDataStructBase* const _data;

public:
	FactoryBase(UWorld* world, FDataStructBase* data) : _world(world), _data(data) {}
	virtual ~FactoryBase() = default;

	virtual FDataStructBase* GetActorInitializationData(uint64_t id) = 0;
};