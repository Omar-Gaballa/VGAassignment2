// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WhatisLove.generated.h"

UCLASS()
class ASSIGNMENT_1C_API AWhatisLove : public ACharacter
{
	GENERATED_BODY()




public:
	// Sets default values for this character's properties
	AWhatisLove();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category = "movement")
	float speed;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "movement")
	float powerUpSpeed;

	
	
	bool walking;


	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	class UAnimMontage* CountessAttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	float MaxHealth;

	//------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	bool bAttacking;


	FORCEINLINE float GetHealth() { return Health; }

	void SetHealth(float Amount);
	/*
	Amount > MaxHealth ? Health = MaxHealth : Health = Amount;
*/


	FORCEINLINE float GetMaxHealt() { return MaxHealth; }

	FORCEINLINE void SetMaxHealth(float Amount) {
		MaxHealth = Amount;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamea;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
	class AMainPlayerController* MainPlayerController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void ToggleCamera();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Sprint();
	void Slow();

	// making the camera behind the character
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// follow camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;


	void LMBDown();
	void ESCDown();
	




};
