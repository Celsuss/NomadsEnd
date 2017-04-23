// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "SpectatorPlayerController.h"

ASpectatorPlayerController::ASpectatorPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	bHidden = false;
	bShowMouseCursor = true;
}

void ASpectatorPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &ASpectatorPlayerController::OnLeftMousePressed);
	InputComponent->BindAction("RightMouseClick", IE_Pressed, this, &ASpectatorPlayerController::OnRightMousePressed);
}

void ASpectatorPlayerController::OnLeftMousePressed()
{
	float locationX;
	float locationY;
	if (GetMousePosition(locationX, locationY))
	{
		AActor* const hitActor = GetTarget(FVector2D(locationX, locationY));
		if (hitActor) {
			UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *hitActor->GetName());
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Miss"));
		}
		//hitActor->IsSelectionGained();
	}
}

void ASpectatorPlayerController::OnRightMousePressed()
{

}

AActor* ASpectatorPlayerController::GetTarget(const FVector2D& ScreenPoint) const
{
	FHitResult Hit;
	if (GetHitResultAtScreenPosition(ScreenPoint, ECC_GameTraceChannel1, true, Hit))
	{
		return Hit.GetActor();
	}
	return nullptr;
}