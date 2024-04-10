// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingCubeActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ARotatingCubeActor::ARotatingCubeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PitchValue = 0.f;
	YawValue = 0.f;
	RollValue = 0.f;

	count = 0;
	state = false;


	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;

	

	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));
}

// Called when the game starts or when spawned
void ARotatingCubeActor::BeginPlay()
{
	Super::BeginPlay();
	
	PitchValue = 1.0f;
	MyMesh->SetMaterial(0, OffMaterial);



}

// Called every frame
void ARotatingCubeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	count += 1;
	// on every frame change rotationg for a smooth rotating actor
	FRotator NewRotation = FRotator(PitchValue, YawValue, RollValue);

	FQuat QuatRotation = FQuat(NewRotation);

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	

	if (count == 3600) {
		count = 0;
		state = !state;
		
	}

	if (state) {
		
		MyMesh->SetMaterial(0, OffMaterial);
	}
	else {
		MyMesh->SetMaterial(0, OnMaterial);
	}
	 
}

