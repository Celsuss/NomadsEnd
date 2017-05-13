// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"

// Data Objects
#include "DataObjects/FDataStructBase.h"
#include "DataObjects/FBuildingData.h"
#include "DataObjects/FStorageDataStruct.h"
#include "DataObjects/FResourceStruct.h"
#include "DataObjects/EResourceEnum.h"

class FNomadsEndGameModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		//Hot reload hack
		//FSlateStyleRegistry::UnRegisterSlateStyle(FStrategyStyle::GetStyleSetName());
		//FStrategyStyle::Initialize();
	}

	virtual void ShutdownModule() override
	{
		//FStrategyStyle::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FNomadsEndGameModule, NomadsEnd, "NomadsEnd" );

//General Log
DEFINE_LOG_CATEGORY(NomadsEndLog);

//Logging during game startup
DEFINE_LOG_CATEGORY(NomadsEndInit);

//Logging for your AI system
DEFINE_LOG_CATEGORY(NomadsEndAI);

//Logging for Critical Errors that must always be addressed
DEFINE_LOG_CATEGORY(NomadsEndCriticalErrors);