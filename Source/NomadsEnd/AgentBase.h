// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AgentBase.generated.h"

class APathNode;

UCLASS()
class NOMADSEND_API AAgentBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAgentBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI Actor")
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI Actor")
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI Actor")
	UCharacterMovementComponent* CharacterMovement;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Actor")
	APathNode* DesiredNode;
};