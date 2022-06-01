// Fill out your copyright notice in the Description page of Project Settings.


#include "Cameradirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameradirector::ACameradirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameradirector::BeginPlay()
{
	Super::BeginPlay();

	// Sets cameraChange to false, otherwise camera would swap on game start
	cameraChange = false;
	
}

void ACameradirector::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	const float TimeBetweenCameraChange = 4.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;

	// Function runs if cameraChange is true, which happens when CameraToggle input is pressed by the player controller
	if (cameraChange) 
	{

		if (TimeToNextCameraChange <= 0.0f) {
			TimeToNextCameraChange += TimeBetweenCameraChange;

			// Establishes a pointer to the player controller for camera switching
			APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

			// Functions will run if player controller is found, otherwise does not run
			if (OurPlayerController) {

				// If current camera is CameraOne, swaps to CameraTwo
				if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne)) {
					OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
				}

				// If current camera is CameraTwo, swaps to CameraOne
				else if (CameraOne) {
					OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
				}
			}
		}

		// Runs when camera finishes swapping to reset cameraToggle function and relevant variables
		else {
			cameraChange = false;
			TimeToNextCameraChange = 0.0f;
		}
	}
}

// Camera swapping function that calls the cameraChange code in Tick function
void ACameradirector::cameraGo()
{
	cameraChange = true;
	TimeToNextCameraChange = 0.0f;
}


/* Old version of the camera swapping functionality
 * Did not allow for player input to swap cameras
 * Automatically swapped cameras at a set interval
 */

/*
// Called every frame
void ACameradirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Float values for camera change intervals
	const float TimeBetweenCameraChange = 4.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;

	//If statement that controls camera change
	if (TimeToNextCameraChange <= 0.0f)
	{

		//Resets time change back to default value
		TimeToNextCameraChange += TimeBetweenCameraChange;

		//Gets the player controller so that it can be used for camera transitions
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{

			//If the player controller's current camera is not camera one and camera two is not null
			if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			{
				//Smoothly blends camera view to camera one
				OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
			}

			//If the player controller's current camera is not camera two and camera two is not null
			else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			{
				//Smoothly blends camera view to camera two
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
	}
}
*/



