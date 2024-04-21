// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Respawnable.h"
#include "RespawnTrigger.generated.h"

UCLASS()
class NORDICGAMEJAM24_API ARespawnTrigger : public ATriggerBox
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	UBoxComponent *BoxCollider;

	// constructor sets default values for this actor's properties
	ARespawnTrigger();

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent *OverlappedComponent,
						AActor *OtherActor,
						UPrimitiveComponent *OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult &SweepResult);
};