// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "UResourceManager.h"

UResourceManager::UResourceManager()
{
	for (uint8 enumInt = (uint8)EResourceEnum::RE_Wood; enumInt < (uint8)EResourceEnum::RE_None; enumInt++)
	{
		ResourceMap.Add((EResourceEnum)enumInt, FResourceStruct((EResourceEnum)enumInt, 0));
	}
}

UResourceManager::~UResourceManager()
{
	ResourceMap.Empty();
}
