// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EResourceEnum : uint8
{
	RE_Wood UMETA(DisplayName = "Wood"),
	RE_Stone UMETA(DisplayName = "Stone"),
	RE_Fish UMETA(DisplayName = "Fish"),
	RE_Meat UMETA(DisplayName = "Meat"),
	RE_Boats UMETA(DisplayName = "Boats"),
	RE_Socks UMETA(DisplayName = "Socks"),
	RE_None UMETA(DisplayName = "None")
};

inline uint8 GetTypeHash(const EResourceEnum A)
{
	return (uint8)A;
}

UENUM(BlueprintType)
enum class EBuildingType : uint8
{
	BT_ProductionBuilding UMETA(DisplayName = "Production Building"),
	BT_GenerationBuilding UMETA(DisplayName = "Generation Building"),
	BT_SpawnBuilding UMETA(DisplayName = "Spawn Building"),
};


inline uint8 GetTypeHash(const EBuildingType A)
{
	return (uint8)A;
}