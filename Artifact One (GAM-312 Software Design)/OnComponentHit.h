/*
*  OnComponentHit
*  Displays name of actor that collides with OnComponentHit actor in debug log
*  Trigger box can be adjusted/changed as needed, default design is a box
*  Currently only useful for debugging, no practical functionality in normal gameplay
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnComponentHit.generated.h"

UCLASS()
class GAM_312_PROJECT_API AOnComponentHit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnComponentHit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Establishes the BoxComponent that is the trigger box for actor collisions
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* MyComp;

	/*Function that runs every time the UBoxComponent registers a hit with another actor
	* HitComp is trigger box for collision
	* OtherActor is objec tthat collides with the box
	* Hit is result from collision if valid collision is made
	*/
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
