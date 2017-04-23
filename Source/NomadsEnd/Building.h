// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FResourceStruct.h"
#include "EResourceEnum.h"
#include "FBuildingData.h"
#include "Building.generated.h"


UCLASS(abstract)
class NOMADSEND_API ABuilding : public AActor
{
	GENERATED_BODY()

	// Begin Actor interface
	//virtual void PostInitializeComponents() override;
	//virtual void Destroyed() override;
	virtual void Tick(float DeltaTime) override;
	//virtual void PostLoad() override;
	// End Actor Interface

	bool _bIsBeingBuilt;

	TMap<EResourceEnum, FResourceStruct> InventoryMap;
	
public:	
	/*	ABuilding* buildingActor = GetWorld()->SpawnActor<ABuilding>(GetClass(), GetActorLocation() + FVector(0.f, 0.f, 300.f), FRotator::ZeroRotator);*/

	ABuilding(const FObjectInitializer& ObjectInitializer);

	virtual void Init(FBuildingData* data);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
