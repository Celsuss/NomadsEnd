// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "UI/StandardHUD.h"
#include "NomadsEndGameModeBase.h"

ANomadsEndGameModeBase::ANomadsEndGameModeBase() : Super() {
	this->HUDClass = AStandardHUD::StaticClass();
}

void ANomadsEndGameModeBase::StartPlay() {
	Super::StartPlay();
}