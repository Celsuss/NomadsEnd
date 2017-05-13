// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "SStandardSlateWidget.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "SStandardSlateWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStandardSlateWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;
	
	ChildSlot
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		[
			SNew(STextBlock)
			.ShadowColorAndOpacity(FLinearColor::Black)
		.ColorAndOpacity(FLinearColor::Red)
		.ShadowOffset(FIntPoint(-1, 1))
		.Font(FSlateFontInfo("Veranda", 16))
		.Text(LOCTEXT("HelloSlate", "Hello, Slate!"))
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE