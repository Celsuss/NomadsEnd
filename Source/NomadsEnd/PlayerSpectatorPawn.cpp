// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "PlayerSpectatorPawn.h"
#include "SpectatorCameraComponent.h"
#include "Camera/CameraComponent.h"

APlayerSpectatorPawn::APlayerSpectatorPawn()
	//: Super(ObjectInitializer.SetDefaultSubobjectClass<UStrategySpectatorPawnMovement>(Super::MovementComponentName))
{
	USphereComponent* collision = GetCollisionComponent();
	collision->SetCollisionProfileName(UCollisionProfile::NoCollision_ProfileName);
	collision->SetEnableGravity(false);
	bAddDefaultMovementBindings = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(collision);
	Camera->SetRelativeRotation(FRotator(-45, 0, 0));

	MovementSpeed = 20;
}

// Called when the game starts or when spawned
void APlayerSpectatorPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerSpectatorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerSpectatorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &APlayerSpectatorPawn::OnMouseScrollUp);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &APlayerSpectatorPawn::OnMouseScrollDown);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerSpectatorPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerSpectatorPawn::MoveRight);
}

void APlayerSpectatorPawn::MoveForward(float Val)
{
	//Camera->MoveForward(Val);
	const FVector move = FVector(MovementSpeed * Val, 0.f, 0.f);
	USphereComponent* collision = GetCollisionComponent();
	collision->MoveComponent(move, collision->GetComponentRotation(), false);
}

void APlayerSpectatorPawn::MoveRight(float Val)
{
	//Camera->MoveRight(Val);
	const FVector move = FVector(0.f, MovementSpeed * Val, 0.f);
	USphereComponent* collision = GetCollisionComponent();
	collision->MoveComponent(move, collision->GetComponentRotation(), false);
}

void APlayerSpectatorPawn::OnMouseScrollUp()
{
	//Camera->OnZoomIn();
	const FVector move = FVector(0.f, 0.f, -MovementSpeed);
	USphereComponent* collision = GetCollisionComponent();
	collision->MoveComponent(move, collision->GetComponentRotation(), false);
}

void APlayerSpectatorPawn::OnMouseScrollDown()
{
	//Camera->OnZoomOut();
	const FVector move = FVector(0.f, 0.f, MovementSpeed);
	USphereComponent* collision = GetCollisionComponent();
	collision->MoveComponent(move, collision->GetComponentRotation(), false);
}

APlayerController* APlayerSpectatorPawn::GetPlayerController()
{
	return Cast<APlayerController>(GetController());
}