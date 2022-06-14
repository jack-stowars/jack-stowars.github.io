// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/Actor.h"
#include "GAM_312_ProjectCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyTeleportBox.generated.h"

/**
 * 
 */
UCLASS()
class GAM_312_PROJECT_API AMyTeleportBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AMyTeleportBox();

	// Function to teleport the player
	UFUNCTION()
		void EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor);

	// Function to prevent the player from instantly teleporting back
	UFUNCTION()
		void ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor);

	// Property for assigning the target teleport box
	UPROPERTY(EditAnywhere, Category = "Teleporter")
		AMyTeleportBox* otherTele;

	// Bool that is used to prevent an infinite teleport loop
	UPROPERTY()
		bool teleporting;
};
