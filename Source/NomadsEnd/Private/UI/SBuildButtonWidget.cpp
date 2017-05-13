#include "NomadsEnd.h"
#include "SBuildButtonWidget.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SBuildButtonWidget::Construct(const FArguments& InArgs)
{
	StandardHUD = InArgs._StandardHUD;

	//ChildSlot
	//	[
	//		SNew(SOverlay)
	//		+ SOverlay::Slot()
	//	.HAlign(HAlign_Center)
	//	.VAlign(VAlign_Top)
	//	[
	//		SNew(STextBlock)
	//		.ColorAndOpacity(FLinearColor::White)
	//	.ShadowColorAndOpacity(FLinearColor::Black)
	//	.ShadowOffset(FIntPoint(-1, 1))
	//	.Font(FSlateFontInfo("Arial", 26))
	//	.Text(FText::FromString("Build Menu"))
	//	]
	//+ SOverlay::Slot()
	//	.HAlign(HAlign_Right)
	//	.VAlign(VAlign_Bottom)
	//	[
	//		SNew(SVerticalBox)
	//		+ SVerticalBox::Slot()
	//	[
	//		SNew(SButton)
	//		.Text(FText::FromString("Construct building"))
	//	.OnClicked(this, &SBuildMenuUI::ConstructBuilding)
	//	]
	//+ SVerticalBox::Slot()
	//	[
	//		SNew(SButton)
	//		.Text(FText::FromString("Blow up building"))
	//	.OnClicked(this, &SBuildMenuUI::ConstructBuilding)
	//	]
	//	]
	//	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
