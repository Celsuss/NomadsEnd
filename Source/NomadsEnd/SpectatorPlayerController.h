// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "NomadsEndTypes.h"
#include "SpectatorPlayerController.generated.h"

class ABuilding;
class UGameDataRepository;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FConstructBuildingDelegate, ABuilding*, building);

UCLASS()
class NOMADSEND_API ASpectatorPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	virtual void SetupInputComponent() override;

	void OnLeftMousePressed();
	void OnRightMousePressed();
	AActor* GetTarget(const FVector2D& screenPoint) const;

	void SetBuildingToConstruct(const uint64_t id);

	const UGameDataRepository* _repository;
	
private:
	void ConstructBuilding(const FVector& pos);

	EControllerActionType m_CurrentAction;
	uint64_t m_BuildingToConstructId;

public:

	void InjectRepository(const UGameDataRepository& repository);

	UPROPERTY()
	FConstructBuildingDelegate OnConstructBuilding;
};