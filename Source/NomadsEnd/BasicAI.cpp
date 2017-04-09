// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "BasicAI.h"


// Sets default values
ABasicAI::ABasicAI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Root Component"));
	CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
	CapsuleComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CapsuleComponent;

	Mesh = CreateOptionalDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component"));
	Mesh->AlwaysLoadOnClient = true;
	Mesh->AlwaysLoadOnServer = true;
	Mesh->bOwnerNoSee = false;
	Mesh->MeshComponentUpdateFlag = EMeshComponentUpdateFlag::AlwaysTickPose;
	Mesh->bCastDynamicShadow = true;
	Mesh->bAffectDynamicIndirectLighting = true;
	Mesh->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	Mesh->SetupAttachment(CapsuleComponent);
	static FName MeshCollisionProfileName(TEXT("CharacterMesh"));
	Mesh->SetCollisionProfileName(MeshCollisionProfileName);
	Mesh->bGenerateOverlapEvents = false;
	Mesh->SetCanEverAffectNavigation(false);
}

// Called when the game starts or when spawned
void ABasicAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}