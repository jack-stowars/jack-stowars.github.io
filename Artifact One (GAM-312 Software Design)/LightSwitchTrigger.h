/*
*  LightSwitchTrigger
*  Toggles point light when player overlaps sphere trigger
*  Controllable elements are light radius/intensity and sphere trigger size
*  Class can be duplicated/modified to create multiple lights of different specifications
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchTrigger.generated.h"

UCLASS()
class GAM_312_PROJECT_API ALightSwitchTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declares point light component
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class UPointLightComponent* PointLight;

	// Declares light component
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		class USphereComponent* LightSphere;

	// Declares light intensity variable
	UPROPERTY(VisibleAnywhere, Category = "Light Switch")
		float LightIntensity;

	/* Declares begin overlap function
	*  OverlappedComp is collision box
	*  OtherActor is player controller
	*  OtherComp is target teleporter
	*/
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/* Declares end overlap function
	*  OverlappedComp is collision box
	*  OtherActor is player controller
	*  OtherComp is target teleporter
	*/
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Declares light toggle function
	UFUNCTION()
		void ToggleLight();
};
