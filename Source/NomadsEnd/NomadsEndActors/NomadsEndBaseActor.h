// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NomadsEndBaseActor.generated.h"

struct FStorageDataStruct;

UCLASS(abstract)
class NOMADSEND_API ANomadsEndBaseActor : public AActor
{
	GENERATED_BODY()
public:
	ANomadsEndBaseActor();
	virtual ~ANomadsEndBaseActor();

	virtual void Init(FDataStructBase* data);
};
