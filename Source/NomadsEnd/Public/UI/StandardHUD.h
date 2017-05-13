// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "StandardHUD.generated.h"

class SStandardSlateWidget;

UCLASS()
class NOMADSEND_API AStandardHUD : public AHUD
{
	GENERATED_BODY()
	
	virtual void PostInitializeComponents() override;

	// Reference to the Build Menu Slate UI.
	TSharedPtr<class SBuildMenuUI> BuildMenuUI;

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Build Menu")
	void ConstructBuilding();

	TSharedPtr<SStandardSlateWidget> MyUIWidget;

	void BeginPlay() override;
};
