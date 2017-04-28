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