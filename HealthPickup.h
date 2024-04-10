// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "item.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_1C_API AHealthPickup : public AItem
{
	GENERATED_BODY()
	
public:
	AHealthPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healing")
	float HealingAmount;

	
	virtual void OnOverlapBegin(UPrimitiveComponent* overlapComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
