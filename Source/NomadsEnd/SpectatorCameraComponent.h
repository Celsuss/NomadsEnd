// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraComponent.h"
#include "SpectatorCameraComponent.generated.h"

/**
 * 
 */
UCLASS(config = Game)
class NOMADSEND_API USpectatorCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:
	USpectatorCameraComponent(const FObjectInitializer& ObjectInitializer);

	//virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;

	void OnZoomIn();

	void OnZoomOut();

	void SetZoomLevel(float NewLevel);

	void UpdateCameraMovement(const APlayerController* InPlayerController);

	void MoveForward(float Val);

	void MoveRight(float Val);

	void ClampCameraLocation(const APlayerController* InPlayerController, FVector& OutCameraLocation);

	/** The minimum offset of the camera. */
	UPROPERTY(config)
	float MinCameraOffset;

	/** The maximum offset of the camera. */
	UPROPERTY(config)
	float MaxCameraOffset;

	/** The angle to look down on the map. */
	UPROPERTY(config)
	FRotator FixedCameraAngle;

	/** How fast the camera moves around when the mouse is at the edge of the screen. */
	UPROPERTY(config)
	float CameraScrollSpeed;

	/** Size of the area at the edge of the screen that will trigger camera scrolling. */
	UPROPERTY(config)
	uint32 CameraActiveBorder;

	/** Minimum amount of camera zoom (How close we can get to the map). */
	UPROPERTY(config)
	float MinZoomLevel;

	/** Maximum amount of camera zoom (How close we can get to the map). */
	UPROPERTY(config)
	float MaxZoomLevel;

	/** Percentage of minimap where center of camera can be placed. */
	UPROPERTY(config)
	float MiniMapBoundsLimit;

	UPROPERTY(config)
	uint8 bShouldClampCamera : 1;

	FBox CameraMovementBounds;

	FVector2D CameraMovementViewportSize;

private:
	void UpdateCameraBounds(const APlayerController* InPlayerController);
	APawn* GetOwnerPawn();
	APlayerController* GetPlayerController();

	FVector IntersectRayWithPlane(const FVector& RayOrigin, const FVector& RayDirection, const FPlane& Plane);

	float InitialPinchAlpha;

	/** Current amount of camera zoom. */
	float ZoomAlpha;

	/** The initial position of the swipe/drag. */
	FVector StartSwipeCoords;
};