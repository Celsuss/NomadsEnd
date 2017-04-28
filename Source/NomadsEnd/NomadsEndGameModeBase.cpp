// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "Factories/BuildingFactory.h"
#include "DataObjects/FBuildingData.h"
#include "NomadsEndActors/ProductionBuilding.h"
#include "NomadsEndActors/Building.h"
#include "UI/StandardHUD.h"
#include "NomadsEndGameModeBase.h"

ANomadsEndGameModeBase::ANomadsEndGameModeBase() : Super() {
	this->HUDClass = AStandardHUD::StaticClass();
}

void ANomadsEndGameModeBase::StartPlay() {
	Super::StartPlay();

	//FBuildingData data;

	//BuildingFactory<AProductionBuilding, FBuildingData>* bf = new BuildingFactory<AProductionBuilding, FBuildingData>(GetWorld(), &data);
}