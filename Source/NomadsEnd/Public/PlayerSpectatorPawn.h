// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SpectatorPawn.h"
#include "PlayerSpectatorPawn.generated.h"

class USpectatorCameraComponent;

UCLASS()
class NOMADSEND_API APlayerSpectatorPawn : public ASpectatorPawn
{
	GENERATED_BODY()
	
	APlayerSpectatorPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerManager")
	USpectatorCameraComponent* Camera;*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "PlayerManager")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerManager")
	float MovementSpeed;

	virtual void MoveForward(float Val) override;

	virtual void MoveRight(float Val) override;

	void OnMouseScrollUp();

	void OnMouseScrollDown();

private:
	APlayerController* GetPlayerController();
};