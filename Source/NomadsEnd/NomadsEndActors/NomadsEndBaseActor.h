// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NomadsEndBaseActor.generated.h"

struct FStorageDataStruct;

UCLASS(abstract)
class NOMADSEND_API ANomadsEndBaseActor : public AActor
{
	GENERATED_BODY()
public:
	ANomadsEndBaseActor();
	virtual ~ANomadsEndBaseActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseActor")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "BaseActor")
	USceneComponent* SceneRootComponent;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Touch, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* TriggerBox;

	virtual void Init(FDataStructBase* data);
};
