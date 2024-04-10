// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"

#include "WhatisLove.h"

AHealthPickup::AHealthPickup()
{
	HealingAmount = 20.f;
}

void AHealthPickup::OnOverlapBegin(UPrimitiveComponent* overlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("AHealthPickup::OnOverlapBegin"));

	AWhatisLove* MainCharacter = Cast<AWhatisLove>(OtherActor);
	if (MainCharacter) {
		MainCharacter->SetHealth(MainCharacter->GetHealth() + HealingAmount);
	}


	Super::OnOverlapBegin(overlapComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}