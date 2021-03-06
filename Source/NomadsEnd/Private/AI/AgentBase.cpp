// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "AgentBase.h"
#include "PathNode.h"

// Sets default values
AAgentBase::AAgentBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;

	BotType = EBotBehaviorType::Passive;

	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text Component"));
	TextRender->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAgentBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAgentBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAgentBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

