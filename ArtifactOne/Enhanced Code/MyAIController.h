/*
*  MyAIController
*  Allows simplistic AI movement by placing pre-determined waypoints
*  AI will pick a random waypoint to move to, carry out the move, and then pick another random waypoint to move to
*  Functionality can be improved to make movements more spaced out, longer delays between moves, and other various AI tweaks
*/

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
