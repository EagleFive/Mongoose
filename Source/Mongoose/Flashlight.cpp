// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"

#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFlashlight::AFlashlight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FlashlightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlashlightMeshComponent"));
	RootComponent = FlashlightMesh;

	SpotLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotlightComponent"));
	SpotLightComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFlashlight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlashlight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

