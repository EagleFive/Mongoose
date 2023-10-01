// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterOne.h"

// Sets default values
ACharacterOne::ACharacterOne()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//bUseControllerRotationYaw = false;

	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//cam->AttachTo(RootComponent);

	// Camera spring arm
	arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	arm->AttachTo(RootComponent);
	arm->TargetArmLength = 500.f;
	arm->SetRelativeRotation(FRotator(-45.f, -90.f, 0.f));
	// Camera Lag setup
	arm->bEnableCameraLag = true;
	arm->CameraLagSpeed = 2; // how quickly the camera lag reaches its target
	arm->CameraLagMaxDistance = 1.5f; // max distance camera can lag behind the current location

	arm->bEnableCameraRotationLag = true;
	arm->CameraRotationLagSpeed = 4;
	arm->CameraLagMaxTimeStep = 1;

	cam->AttachTo(arm, USpringArmComponent::SocketName);

	// initialize character jumping state to false
	jumping = false;

	firstPerson = false;
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

	// if jumping, call Unreal built-in jump function
	if (jumping)
	{
		Jump();
	}

}

// Called to bind functionality to input
void ACharacterOne::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("Horizontal", this, &ACharacterOne::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &ACharacterOne::VerticalMove);
	//InputComponent->BindAxis("HorizontalRot", this, &ACharacterOne::HorizontalRot);
	//InputComponent->BindAxis("VerticalRot", this, &ACharacterOne::VerticalRot);
	InputComponent->BindAxis("Zoom", this, &ACharacterOne::Zoom);

	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterOne::CheckJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacterOne::CheckJump);
	//InputComponent->BindAction("ChangeCamera", IE_Pressed, this, &ACharacterOne::Switch);
	InputComponent->BindAction("CharacterSwitch", IE_Pressed, this, &ACharacterOne::SwitchCharacter);
}

/*
 void ACharacterOne::HorizontalRot(float value)
{
	if (value)
	{
		AddActorLocalRotation(FRotator(0, value, 0));
	}
}
*/

/*
void ACharacterOne::VerticalRot(float value)
{
	if (value)
	{
		float temp = 0;
		if (firstPerson)
		{
			temp = cam->GetRelativeRotation().Pitch + value;
			if (temp < 65 && temp > -65)
			{
				cam->AddLocalRotation(FRotator(value, 0, 0));
			}
		}
		else
		{
			temp = arm->GetRelativeRotation().Pitch + value;
			if (temp < 25 && temp > -65)
			{
				arm->AddLocalRotation(FRotator(value, 0, 0));
			}
		}
	}
}
*/

void ACharacterOne::Zoom(float value)
{
	if (value)
	{
		float temp = arm->TargetArmLength + (value * -20);
		if (temp < 500 && temp > 140)
		{
			arm->TargetArmLength = temp;
		}
	}
}

/*
void ACharacterOne::Switch()
{
	if (firstPerson)
	{
		arm->TargetArmLength = 500.f;
		arm->SetRelativeRotation(FRotator(-45.f, 90.f, 0.f));
		cam->SetRelativeRotation(FRotator(0,0,0));
		cam->AttachTo(arm, USpringArmComponent::SocketName);
		firstPerson = false;
	}
	else
	{
		cam->AttachTo(RootComponent);
		firstPerson = true;
	}
}
*/

void ACharacterOne::CheckJump()
{
	if (jumping)
	{
		jumping = false;
	}
	else
	{
		jumping = true;
	}
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

void ACharacterOne::SwitchCharacter()
{
	if (CharacterTwo && GetController())
	{
		AController* temp = GetController();
		if (temp)
		{
			temp->UnPossess();
			temp->Possess(CharacterTwo);
		}
	}
}