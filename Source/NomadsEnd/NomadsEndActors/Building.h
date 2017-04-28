// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataObjects/FResourceStruct.h"
#include "DataObjects/EResourceEnum.h"
#include "DataObjects/FBuildingData.h"
#include "Building.generated.h"


UCLASS(abstract)
class NOMADSEND_API ABuilding : public ANomadsEndBaseActor
{
	GENERATED_BODY()

	// Begin Actor interface
	//virtual void PostInitializeComponents() override;
	//virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;
	//virtual void PostLoad() override;
	// End Actor Interface

	bool _bIsBeingBuilt;
	FBuildingData* _data;

	TMap<EResourceEnum, FResourceStruct> InventoryMap;
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

	virtual void Init(FDataStructBase* data) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
