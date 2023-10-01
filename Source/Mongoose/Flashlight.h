// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Flashlight.generated.h"

UCLASS()
class MONGOOSE_API AFlashlight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlashlight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* FlashlightMesh;

	UPROPERTY(EditAnywhere)
		class USpotLightComponent* SpotLightComponent;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};