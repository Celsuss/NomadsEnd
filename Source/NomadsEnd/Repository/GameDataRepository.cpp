// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "GameDataRepository.h"

#include "Json.h"
#include "JsonObjectConverter.h"

UGameDataRepository::UGameDataRepository()
{
	_saveDir = FPaths::ConvertRelativePathToFull(FPaths::GameDir()+"/Source/");
	_fileName = FString("TestJson.json");
}

UGameDataRepository::~UGameDataRepository()
{
}

bool UGameDataRepository::SaveData(const FStorageDataStruct &inStruct)
{
	TSharedPtr<FJsonObject> jsonObject = FJsonObjectConverter::UStructToJsonObject(inStruct);

	FString outputString;
	TSharedRef<TJsonWriter<>> writer = TJsonWriterFactory<>::Create(&outputString);

	FJsonSerializer::Serialize(jsonObject.ToSharedRef(), writer);

	return WriteToDisk(outputString);
}

bool UGameDataRepository::WriteToDisk(FString jsonString)
{
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();
	bool result = false;

	// Get absolute file path
	FString absoluteFilePath = _saveDir + "/" + _fileName;

	if (platformFile.CreateDirectoryTree(*_saveDir))
	{
		// Allow overwriting or file doesn't already exist
		if (_allowOverwriting || !platformFile.FileExists(*absoluteFilePath))
		{
			result = FFileHelper::SaveStringToFile(jsonString, *absoluteFilePath);
		}
	}
	return result;
}

FStorageDataStruct* UGameDataRepository::LoadData() {
	
	TSharedPtr<FJsonObject> jsonObject;
	FString inputString;

	// Get absolute file path
	FString absoluteFilePath = _saveDir + "/" + _fileName;

	FFileHelper::LoadFileToString(inputString, *absoluteFilePath);

	TSharedRef<TJsonReader<>> reader = TJsonReaderFactory<>::Create(inputString);

	FJsonSerializer::Deserialize(reader, jsonObject);

	FStorageDataStruct* dataStructOut = new FStorageDataStruct();
	bool result = FJsonObjectConverter::JsonObjectToUStruct(jsonObject.ToSharedRef(), dataStructOut, 0, 0);

	if (result)
	{
		return dataStructOut;
	}
	
	return 0;
}