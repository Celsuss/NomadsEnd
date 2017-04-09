// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "CameraPawn.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpring"));
	CameraSpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraSpringArm);

	MovementSpeed = 10;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveHorizontalY", this, &ACameraPawn::MoveHorizontalY);
	InputComponent->BindAxis("MoveHorizontalZ", this, &ACameraPawn::MoveHorizontalZ);
	InputComponent->BindAxis("MoveVertical", this, &ACameraPawn::MoveVertical);
}

void ACameraPawn::MoveHorizontalY(float AxisValue)
{
	const FVector move = FVector(0.f, MovementSpeed * AxisValue, 0.f);
	SceneRoot->MoveComponent(move, SceneRoot->GetComponentRotation(), false);
}

void ACameraPawn::MoveHorizontalZ(float AxisValue)
{
	const FVector move = FVector(0.f, 0.f, MovementSpeed * AxisValue);
	SceneRoot->MoveComponent(move, SceneRoot->GetComponentRotation(), false);
}

void ACameraPawn::MoveVertical(float AxisValue)
{
	const FVector move = FVector(MovementSpeed * AxisValue, 0.f, 0.f);
	SceneRoot->MoveComponent(move, SceneRoot->GetComponentRotation(), false);
}