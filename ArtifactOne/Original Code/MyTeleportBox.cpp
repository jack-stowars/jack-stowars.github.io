// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTeleportBox.h"

AMyTeleportBox::AMyTeleportBox()
{
	// Adds dynamics for beginning and ending overlap for teleportation functionality
	OnActorBeginOverlap.AddDynamic(this, &AMyTeleportBox::EnterTeleporter);
	OnActorEndOverlap.AddDynamic(this, &AMyTeleportBox::ExitTeleporter);
	teleporting = false;
}

void AMyTeleportBox::BeginPlay()
{
	Super::BeginPlay();
}

// Function for teleporting player to the target teleport box
void AMyTeleportBox::EnterTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	// If another actor is overlapping the trigger box
	if (otherActor && otherActor != this)
	{
		// If a teleport exit box is designated
		if (otherTele)
		{
			// Gets the player character
			AGAM_312_ProjectCharacter* character = Cast<AGAM_312_ProjectCharacter>(otherActor);

			// If a valid player character is cast and the player is not teleporting
			if (character && !otherTele->teleporting)
			{
				// Sets teleport bool to "true", rotates the character properly, and move it to the teleporter exit
				teleporting = true;
				character->SetActorRotation(otherTele->GetActorRotation());
				character->GetController()->SetControlRotation(character->GetActorRotation());
				character->SetActorLocation(otherTele->GetActorLocation());
			}
		}
	}
}

// Function to prevent infinite teleport loops
void AMyTeleportBox::ExitTeleporter(class AActor* overlappedActor, class AActor* otherActor)
{
	// If another actor is overlapping the trigger box
	if (otherActor && otherActor != this)
	{
		// If a teleport exit box is designated and teleporting is false
		if (otherTele && !teleporting)
		{
			// Sets teleport exit bool to false to prevent infinite teleport loop
			otherTele->teleporting = false;
		}
	}
}