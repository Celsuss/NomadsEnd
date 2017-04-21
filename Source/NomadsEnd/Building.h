// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FResourceStruct.h"
#include "EResourceEnum.h"
#include "Building.generated.h"

UCLASS(abstract)
class NOMADSEND_API ABuilding : public AActor
{
	GENERATED_BODY()

	bool _bIsBeingBuilt;

	TArray<FResourceStruct> CostMap;
	TMap<EResourceEnum, FResourceStruct> InventoryMap;
	
public:	
	// Sets default values for this actor's properties
	ABuilding();
	/*	ABuilding* buildingActor = GetWorld()->SpawnActor<ABuilding>(GetClass(), GetActorLocation() + FVector(0.f, 0.f, 300.f), FRotator::ZeroRotator);*/


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
