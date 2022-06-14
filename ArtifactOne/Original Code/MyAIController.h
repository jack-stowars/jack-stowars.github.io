// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "MyAIController.generated.h"


/**
 * 
 */
UCLASS()
class GAM_312_PROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:
	AMyAIController();

	void BeginPlay() override;

	// Function that allows the AI to move again once it reaches the first target point
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	// Array for storing target points
	UPROPERTY()
		TArray<AActor*> Waypoints;

	// Function to select a random target point from the array of target points
	UFUNCTION()
		ATargetPoint* GetRandomWaypoint();

	// Function that moves the AI to the selected target point
	UFUNCTION()
		void GoToRandomWaypoint();
};
