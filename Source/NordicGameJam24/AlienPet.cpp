// Fill out your copyright notice in the Description page of Project Settings.

#include "AlienPet.h"
#include "Math/Rotator.h"

// Sets default values
AAlienPet::AAlienPet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAlienPet::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAlienPet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isFollowing)
	{
		this->FacePlayer(DeltaTime);
		this->FollowPlayer(DeltaTime);
	}
}

FVector AAlienPet::DirectionToPlayer(AActor *PlayerCharacter, float DeltaTime)
{
	return FVector(); // PlayerCharacter->GetActorLocation() - GetActor()->GetActorLocation();
}

void AAlienPet::FacePlayer(float deltaTime)
{
	FRotator newRotator = DirectionToPlayer(playerCharacter, deltaTime).Rotation();
	newRotator.Yaw = FRotator::ClampAxis(newRotator.Yaw);
	SetActorRotation(newRotator);

	//FaceRotation(newRotator, deltaTime);
}

bool AAlienPet::IsInRange()
{
	return false;
}

void AAlienPet::FollowPlayer(float DeltaTime)
{
	if (this->IsInRange())
	{
		timeSinceInRange = 0.f;
		return;
	}
	timeSinceInRange += DeltaTime;

	if (timeSinceInRange >= waitBeforeFollow)
	{
	}
}
