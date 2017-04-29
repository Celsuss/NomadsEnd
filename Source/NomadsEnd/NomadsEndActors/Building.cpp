// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "Building.h"


// Sets default values
ABuilding::ABuilding()
	: Super()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*TSubobject<UStaticMeshComponent> mesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/Mesh/Cube/YourMesh"));
	mesh->SetStaticMesh(MeshObj.Object);*/
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuilding::Init(FDataStructBase* data)
{
	_data = (FBuildingData*)data;
}