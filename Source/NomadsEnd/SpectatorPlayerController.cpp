// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "Building.h"
#include "SpectatorPlayerController.h"

ASpectatorPlayerController::ASpectatorPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	bHidden = false;
	bShowMouseCursor = true;
	m_CurrentAction = EControllerActionType::Selecting;
}

void ASpectatorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ASpectatorPlayerController::OnLeftMousePressed);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ASpectatorPlayerController::OnRightMousePressed);
}

void ASpectatorPlayerController::OnLeftMousePressed()
{
	FVector2D location;
	float locationX;
	float locationY;
	if (GetMousePosition(locationX, locationY))
	{
		FHitResult hit;
		if (GetHitResultAtScreenPosition(FVector2D(locationX, locationY), ECC_GameTraceChannel1, true, hit))
		{
			if (m_CurrentAction == EControllerActionType::Building)
				ConstructBuilding(hit.ImpactPoint);
		}
	}
}

void ASpectatorPlayerController::OnRightMousePressed()
{
	m_BuildingToConstruct = nullptr;
	m_CurrentAction = EControllerActionType::Selecting;
}

AActor* ASpectatorPlayerController::GetTarget(const FVector2D& screenPoint) const
{
	FHitResult Hit;
	if (GetHitResultAtScreenPosition(screenPoint, ECC_GameTraceChannel1, true, Hit))
	{
		return Hit.GetActor();
	}
	return nullptr;
}

void ASpectatorPlayerController::SetBuildingToConstruct(ABuilding* building)
{
	m_CurrentAction = EControllerActionType::Building;
	m_BuildingToConstruct = building;
}

void ASpectatorPlayerController::ConstructBuilding(const FVector& pos)
{
	UE_LOG(LogTemp, Warning, TEXT("Build"));
	//if (m_CurrentAction != EControllerActionType::Building || !m_BuildingToConstruct) return;

	m_BuildingToConstruct = nullptr;
	m_CurrentAction = EControllerActionType::Selecting;
	// TODO: Call Factory to create building
}