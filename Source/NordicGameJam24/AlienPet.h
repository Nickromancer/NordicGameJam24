// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AlienPet.generated.h"

UCLASS()
class NORDICGAMEJAM24_API AAlienPet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAlienPet();

	UPROPERTY(EditAnywhere)
	float waitBeforeFollow = 1.f;

	UPROPERTY(EditAnywhere)
	AActor *playerCharacter = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector DirectionToPlayer(AActor *PlayerCharacter, float DeltaTime);
	void FacePlayer(float DeltaTime);
	void FollowPlayer(float DeltaTime);
	bool IsInRange();
	bool isFollowing = true;
	float timeSinceInRange = 0.0f;
	float speed = 50.0f;
	float followRange = 50.0f;
};
