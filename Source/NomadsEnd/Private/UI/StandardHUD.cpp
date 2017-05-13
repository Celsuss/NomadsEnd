// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "StandardHUD.h"
#include "SBuildMenuUI.h"

void AStandardHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(BuildMenuUI, SBuildMenuUI).StandardHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(BuildMenuUI.ToSharedRef()));
	}
}

void AStandardHUD::BeginPlay() {

	Super::BeginPlay();

	//MyUIWidget = SNew(SStandardSlateWidget).OwnerHUD(this);

	//GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MyUIWidget.ToSharedRef()));

	//MyUIWidget->SetVisibility(EVisibility::Visible);
}



