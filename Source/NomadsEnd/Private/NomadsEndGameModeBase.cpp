// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "UI/StandardHUD.h"
#include "Repository/GameDataRepository.h"
#include "SpectatorPlayerController.h"
#include "NomadsEndGameModeBase.h"

ANomadsEndGameModeBase::ANomadsEndGameModeBase() : Super() {
	this->HUDClass = AStandardHUD::StaticClass();
}

void ANomadsEndGameModeBase::StartPlay() {
	Super::StartPlay();

	Repository = NewObject<UGameDataRepository>();

	auto playerController = Cast<ASpectatorPlayerController>(GetWorld()->GetFirstPlayerController());
	playerController->InjectRepository(*Repository);
}