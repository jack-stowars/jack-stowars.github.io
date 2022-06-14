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
	
}

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

