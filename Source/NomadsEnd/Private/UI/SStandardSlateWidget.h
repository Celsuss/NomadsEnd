// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class NOMADSEND_API SStandardSlateWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SStandardSlateWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class AStandardHUD>, OwnerHUD)

	SLATE_END_ARGS()

public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AStandardHUD> OwnerHUD;
};
