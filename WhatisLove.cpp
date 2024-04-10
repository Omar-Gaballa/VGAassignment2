// Fill out your copyright notice in the Description page of Project Settings.


#include "WhatisLove.h"

#include "MainPlayerController.h"
#include "ModuleDescriptor.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
AWhatisLove::AWhatisLove()
{
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//.........................................................................New

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//..................................................New

	// Do not rotate the camera when the controller rotates with the mouse movement
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

	//................................................New

	// for the sprint function
	
	speed = 40.f;
	powerUpSpeed = 3.f;
	walking = true;

	Health = 80.f;
	MaxHealth = 100.f;
}

// Called when the game starts or when spawned
void AWhatisLove::BeginPlay()
{
	Super::BeginPlay();

	MainPlayerController = Cast<AMainPlayerController>(GetController());

	
}

void AWhatisLove::MoveForward(float Value) {
	//FVector Forward = GetActorForwardVector();
	//AddMovementInput(Forward, Value);

	if ((Controller != NULL) && (Value != 0.0f)) {
		// find out which way forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get forward vector

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value * speed);
	}
}

void AWhatisLove::MoveRight(float Value) {
	FVector Right = GetActorRightVector();
	AddMovementInput(Right, Value * speed);


	if ((Controller != NULL) && (Value != 0.0f)) {
		// find out which way forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		// get forward vector

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

// Called every frame
void AWhatisLove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWhatisLove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//.......................................................................NEW
	PlayerInputComponent->BindAxis("MoveForward", this, &AWhatisLove::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWhatisLove::MoveRight);

	//..................................................New
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	//..................................................New
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//..................................................New
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AWhatisLove::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AWhatisLove::Sprint);

	PlayerInputComponent->BindAction("Slow", IE_Pressed, this, &AWhatisLove::Slow);
	PlayerInputComponent->BindAction("Slow", IE_Released, this, &AWhatisLove::Slow);
	PlayerInputComponent->BindAction("ToggleCamera", IE_Pressed, this, &AWhatisLove::ToggleCamera);


	//pause/resume

	PlayerInputComponent->BindAction("ESC", IE_Pressed, this, &AWhatisLove::ESCDown);

}


void AWhatisLove::Sprint()
{
	walking = !walking;
	if (walking)
	{
		speed = 0.5f;
	}
	else
	{
		speed = 4;
	}

}

void AWhatisLove::Slow()
{
	walking = !walking;
	if (walking)
	{
		speed = 40.f;
	}
	else
	{
		speed = 100.f;
	}
}

void AWhatisLove::ToggleCamera()
{
	if (FollowCamera->IsActive())
	{
		FollowCamera->Deactivate();
		CameraBoom->Deactivate();
		GetMesh()->SetVisibility(false); // Hide the mesh component
	}
	else
	{
		FollowCamera->Activate();
		CameraBoom->Activate();
		GetMesh()->SetVisibility(true); // Show the mesh component
	}
}

void AWhatisLove::SetHealth(float Amount)
{
	if (Amount > MaxHealth)
	{
		Health = MaxHealth;
	}else if(Amount<0)
	{
		Health = 0;
	}else
	{
		Health = Amount;
	}
}

void AWhatisLove::ESCDown()
{
	if(MainPlayerController)
	{
		MainPlayerController->TogglePauseMenu();
	}
}

