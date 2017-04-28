// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "NomadsEndActors/Building.h"
#include "SBuildMenuUI.h"
#include "SlateOptMacros.h"
#include "UI/StandardHUD.h"
#include "SpectatorPlayerController.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SBuildMenuUI::Construct(const FArguments& InArgs)
{
	StandardHUD = InArgs._StandardHUD;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::White)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ShadowOffset(FIntPoint(-1, 1))
			.Font(FSlateFontInfo("Arial", 26))
			.Text(FText::FromString("Build Menu"))
		]
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Construct building"))
				.OnClicked(this, &SBuildMenuUI::ConstructBuilding)
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SBuildMenuUI::ConstructBuilding()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("ConstructBuilding"));

		if (StandardHUD->GetWorld())
		{
			ASpectatorPlayerController* controller = Cast<ASpectatorPlayerController>(StandardHUD->GetWorld()->GetFirstPlayerController());
			if (controller) {
				ABuilding* build = new ABuilding();
				controller->SetBuildingToConstruct(build);
			}
			else
				GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("No controller"));
		}
		else
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("No world"));
	}

	// actually the BlueprintImplementable function of the HUD is not called; uncomment if you want to handle the OnClick via Blueprint
	//StandardHUD->ConstructBuilding();
	return FReply::Handled();
}