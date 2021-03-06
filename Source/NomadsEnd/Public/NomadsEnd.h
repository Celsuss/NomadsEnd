// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "SlateBasics.h"
#include "SlateExtras.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(NomadsEndLog, Log, All);

//Logging during game startup
DECLARE_LOG_CATEGORY_EXTERN(NomadsEndInit, Log, All);

//Logging for your AI system
DECLARE_LOG_CATEGORY_EXTERN(NomadsEndAI, Log, All);

//Logging for Critical Errors that must always be addressed
DECLARE_LOG_CATEGORY_EXTERN(NomadsEndCriticalErrors, Log, All);