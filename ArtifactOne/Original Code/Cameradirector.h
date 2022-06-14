// Fill out your copyright notice in the Description page of Project Settings.

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

	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraOne;

	UPROPERTY(EditAnywhere, Category = Cameras)
		AActor* CameraTwo;

	float TimeToNextCameraChange;
};
