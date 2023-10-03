// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Character.h"
#include "CharacterOne.generated.h"

UCLASS()
class MONGOOSE_API ACharacterOne : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterOne();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void HorizontalMove(float value);
	void VerticalMove(float value);
	//void HorizontalRot(float value);
	//void VerticalRot(float value);

	void SwitchCharacter();

	void CheckJump();

	void Zoom(float value);
	//void SwitchCamera();

	UPROPERTY()
		bool jumping;

	UPROPERTY()
		bool firstPerson;

	UPROPERTY()
		UCameraComponent* cam;

	UPROPERTY()
		USpringArmComponent* arm;

	UPROPERTY(EditAnywhere, Category = "Possession")
		ACharacterOne* otherCharacter;
};
