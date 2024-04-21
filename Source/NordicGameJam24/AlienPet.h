// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

#include "AlienPet.generated.h"

UCLASS()
class NORDICGAMEJAM24_API AAlienPet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAlienPet();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UCapsuleComponent *CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent *BaseMesh;

	UPROPERTY(EditAnywhere)
	float waitBeforeFollow = 1.f;

	UPROPERTY(EditAnywhere)
	float Speed = .5f;

	UPROPERTY(EditAnywhere)
	bool isFollowing = true;

	UPROPERTY(EditAnywhere)
	float followRange = 50.0f;

	FVector PlayerLocation;
	FVector CurrentLocation;

	UPROPERTY(EditAnywhere)
	USoundBase *sound;

	UPROPERTY(EditAnywhere)
	int inverseSoundProbablity = 1000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector DirectionToPlayer();
	void FacePlayer(float DeltaTime);
	void FollowPlayer(float DeltaTime);
	bool IsInRange();
	float timeSinceInRange = 0.0f;
	void RandomPlaySound(float DeltaTime);
	float timeSinceLastNoise = 0.f;
	float minTimeBetweenNoises = 1.f;
};