// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "SpectatorPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class NOMADSEND_API ASpectatorPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	virtual void SetupInputComponent() override;

	void OnLeftMousePressed();
	void OnRightMousePressed();

	AActor* GetTarget(const FVector2D& ScreenPoint) const;
};