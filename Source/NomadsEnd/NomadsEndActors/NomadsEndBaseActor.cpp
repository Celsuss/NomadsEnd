// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"

#include "DataObjects/FStorageDataStruct.h"

#include "NomadsEndBaseActor.h"

ANomadsEndBaseActor::ANomadsEndBaseActor()
{
	SceneRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	RootComponent = SceneRootComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));

	MeshComponent->SetupAttachment(RootComponent);
	TriggerBox->SetupAttachment(RootComponent);

	
}

ANomadsEndBaseActor::~ANomadsEndBaseActor()
{
}

void ANomadsEndBaseActor::Init(FDataStructBase* data) {


}