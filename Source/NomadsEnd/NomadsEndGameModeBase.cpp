// Fill out your copyright notice in the Description page of Project Settings.

#include "NomadsEnd.h"
#include "FStorageDataStruct.h"
#include "Json.h"
#include "FBuildingData.h"
#include "JsonObjectConverter.h"
#include "NomadsEndGameModeBase.h"


ANomadsEndGameModeBase::ANomadsEndGameModeBase() {
	
	FStorageDataStruct dataStruct = FStorageDataStruct();

	FBuildingData buildingData = FBuildingData();

	dataStruct.Root.Add(buildingData);
	
	TSharedPtr<FJsonObject> obj = FJsonObjectConverter::UStructToJsonObject(dataStruct);


	FString OutputString;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);

	FJsonSerializer::Serialize(obj.ToSharedRef(), Writer);

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	const FString SaveDir = FString("C:/Users/Tomas/Documents/Unreal Projects/NomadsEnd/Source");
	const FString FileName = FString("TestJson.json");
	bool AllowOverwriting = true;

	// Get absolute file path
	FString AbsoluteFilePath = SaveDir + "/" + FileName;

	if (PlatformFile.CreateDirectoryTree(*SaveDir))
	{
		// Allow overwriting or file doesn't already exist
		if (AllowOverwriting || !PlatformFile.FileExists(*AbsoluteFilePath))
		{
			FFileHelper::SaveStringToFile(OutputString, *AbsoluteFilePath);
		}
	}

	//TSharedPtr<FJsonObject> obj2 = FJsonObjectConverter::JsonObjectStringToUStruct

	//FString InputString;
	//FFileHelper::LoadFileToString(InputString, *AbsoluteFilePath);

	//TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InputString);

	//FStorageDataStruct dataStructOut;
	//TSharedPtr<FStorageDataStruct> inObj = FJsonObjectConverter::JsonObjectStringToUStruct(F;
}

