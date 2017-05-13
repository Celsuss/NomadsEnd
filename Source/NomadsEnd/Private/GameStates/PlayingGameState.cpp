// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "NomadsEndActors/Building.h"
#include "PlayingGameState.h"

void APlayingGameState::AddConstructionBuilding(ABuilding* building) {
	ConstructionArray.Add(building);
}

ABuilding* APlayingGameState::GetConstructionBuilding() {
	if (ConstructionArray.Num() <= 0) return nullptr;

	return ConstructionArray[0];
}