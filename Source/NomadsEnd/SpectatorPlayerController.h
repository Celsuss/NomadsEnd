// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "NomadsEndTypes.h"
#include "SpectatorPlayerController.generated.h"

class ABuilding;
class BuildingFactory;
class APlayingGameState;
class UGameDataRepository;

UCLASS()
class NOMADSEND_API ASpectatorPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	virtual void SetupInputComponent() override;

	void OnLeftMousePressed();
	void OnRightMousePressed();
	AActor* GetTarget(const FVector2D& screenPoint) const;

	void SetBuildingToConstruct(const uint64_t id);
	
private:
	void ConstructBuilding(const FVector& pos);

	APlayingGameState* m_GameState;

	EControllerActionType m_CurrentAction;
	uint64_t m_BuildingToConstructId;

	UGameDataRepository* m_DataRepository;
	BuildingFactory* m_BuildingFactory;
};