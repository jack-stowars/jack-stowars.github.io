// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchTrigger.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ALightSwitchTrigger::ALightSwitchTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Sets light intensity for point lights
	LightIntensity = 3000.0f;

	// Establishes PointLight object, as well as light intensity, visibliity, and RootComponent
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = false;
	RootComponent = PointLight;

	// Establishes the collision box for the point light, as well as the radius, name, and RootComponent
	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	// Establishes OnOverlapBegin and OnOverlapEnd functions for LightSphere trigger
	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ALightSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when OnOverlapBegin (light on) and OnOverlapEnd (light off) functions are called
void ALightSwitchTrigger::ToggleLight()
{
	PointLight->ToggleVisibility();
}

// Function is called when an actor begins to overlap the LightSphere trigger
void ALightSwitchTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

// Function is called when an actor ends overlap with the LightSphere trigger
void ALightSwitchTrigger::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}
