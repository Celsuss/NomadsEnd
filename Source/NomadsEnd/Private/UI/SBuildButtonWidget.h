// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "NomadsEndActors/Building.h"
#include "Widgets/SCompoundWidget.h"

/**
*
*/
class NOMADSEND_API SBuildButtonWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBuildButtonWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AStandardHUD>, StandardHUD)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply ConstructBuilding();

	TWeakObjectPtr<class AStandardHUD> StandardHUD;


};
