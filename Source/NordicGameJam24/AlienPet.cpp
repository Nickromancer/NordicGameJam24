// Fill out your copyright notice in the Description page of Project Settings.

#include "AlienPet.h"
#include "Math/Rotator.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"

// Sets default values
AAlienPet::AAlienPet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);
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
	PlayerLocation = UGameplayStatics::GetPlayerController(this, 0)->GetPawn()->GetActorLocation();
	CurrentLocation = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("Player Location: %s"), *PlayerLocation.ToString());
	UE_LOG(LogTemp, Display, TEXT("My Location: %s"), *GetActorLocation().ToString());
	if (isFollowing)
	{
		FacePlayer(DeltaTime);
		FollowPlayer(DeltaTime);
	}
}

FVector AAlienPet::DirectionToPlayer()
{
	FVector TargetLocation = GetActorLocation();
	return (PlayerLocation - TargetLocation);
}

void AAlienPet::FacePlayer(float deltaTime)
{
	FRotator newRotator = DirectionToPlayer().Rotation();
	newRotator.Yaw = FRotator::ClampAxis(newRotator.Yaw);
	SetActorRotation(newRotator);

	// FaceRotation(newRotator, deltaTime);
}

bool AAlienPet::IsInRange()
{
	// if(Dist(CurrentLocation, PlayerLocation) > )
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
		SetActorLocation(CurrentLocation + DirectionToPlayer().Normalize() * Speed);
	}
}
