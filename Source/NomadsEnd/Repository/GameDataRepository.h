// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
*  Use this class to Load and Save all entity data
*/

#include "DataObjects/FStorageDataStruct.h"
#include "GameDataRepository.generated.h"

UCLASS(abstract)
class NOMADSEND_API UGameDataRepository : public UObject
{
	GENERATED_BODY()

	virtual bool WriteToDisk(FString jsonString);

	FString _saveDir;
	FString _fileName;
	bool _allowOverwriting = false;

public:
	UGameDataRepository();
	virtual ~UGameDataRepository();

	virtual FStorageDataStruct* LoadData();
	virtual bool SaveData(const FStorageDataStruct &inStruct);
};
