// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterOne.h"

// Sets default values
ACharacterOne::ACharacterOne()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACharacterOne::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterOne::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &ACharacterOne::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &ACharacterOne::VerticalMove);
}

void ACharacterOne::HorizontalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorRightVector(), value);
	}
}

void ACharacterOne::VerticalMove(float value)
{
	if (value)
	{
		AddMovementInput(GetActorForwardVector(), value);
	}
}
