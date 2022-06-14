// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


AMyAIController::AMyAIController()
{
	
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	// Gets all target points for the AI to move between
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	// Calls the function that moves the AI to a target point
	GoToRandomWaypoint();
}

ATargetPoint* AMyAIController::GetRandomWaypoint()
{
	// Generates a random index to choose which target point to move to
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void AMyAIController::GoToRandomWaypoint()
{
	// Moves the AI to the target point
	MoveToActor(GetRandomWaypoint());
}

void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	// Allows the AI to instantaneously move to multiple points one after the other
	Super::OnMoveCompleted(RequestID, Result);

	GoToRandomWaypoint();
}
