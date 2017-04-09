// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "AIPath.h"


// Sets default values
AAIPath::AAIPath()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIPath::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIPath::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

