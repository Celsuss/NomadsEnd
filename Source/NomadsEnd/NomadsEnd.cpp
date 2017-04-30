// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"

// Data Objects
#include "DataObjects/FDataStructBase.h"
#include "DataObjects/FBuildingData.h"
#include "DataObjects/FStorageDataStruct.h"
#include "DataObjects/FResourceStruct.h"
#include "DataObjects/EResourceEnum.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, NomadsEnd, "NomadsEnd" );

//General Log
DEFINE_LOG_CATEGORY(NomadsEndLog);

//Logging during game startup
DEFINE_LOG_CATEGORY(NomadsEndInit);

//Logging for your AI system
DEFINE_LOG_CATEGORY(NomadsEndAI);

//Logging for Critical Errors that must always be addressed
DEFINE_LOG_CATEGORY(NomadsEndCriticalErrors);