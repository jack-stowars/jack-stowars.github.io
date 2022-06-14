/* 
*  Cameradirector
*  Allows player to switch between player camera and mounted camera in environment
*  Currently only works between two cameras, can be expanded upon
*/ 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cameradirector.generated.h"

UCLASS()
class GAM_312_PROJECT_API ACameradirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameradirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Establishes pointer for CameraOne
	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraOne;

	// Establishes pointer for CameraTwo
	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraTwo;

	// Input function to toggle camera switching
	void cameraGo();

	// Variables for camera toggling
	float TimeToNextCameraChange;
	bool cameraChange;
};
