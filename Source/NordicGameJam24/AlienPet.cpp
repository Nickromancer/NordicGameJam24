// Fill out your copyright notice in the Description page of Project Settings.

#include "AlienPet.h"
#include "Math/Rotator.h"
#include "Math/Vector.h"
#include "Components/PrimitiveComponent.h"

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
	this->RandomPlaySound(DeltaTime);
	UE_LOG(LogTemp, Display, TEXT("Player Location: %s"), *PlayerLocation.ToString());
	UE_LOG(LogTemp, Display, TEXT("My Location: %s"), *GetActorLocation().ToString());
	UE_LOG(LogTemp, Display, TEXT("Time since Follow: %f"), timeSinceInRange);
	if (isFollowing)
	{
		this->FacePlayer(DeltaTime);
		this->FollowPlayer(DeltaTime);
	}
}

FVector AAlienPet::DirectionToPlayer(float DeltaTime)
{
	return FVector(); // PlayerCharacter->GetActorLocation() - GetActor()->GetActorLocation();
}

void AAlienPet::FacePlayer(float deltaTime)
{
	FRotator newRotator = DirectionToPlayer(deltaTime).Rotation();
	newRotator.Yaw = FRotator::ClampAxis(newRotator.Yaw);
	SetActorRotation(newRotator);

	// FaceRotation(newRotator, deltaTime);
}

bool AAlienPet::IsInRange()
{
	// if(Dist(CurrentLocation, PlayerLocation) > )
	if (FVector::Distance(PlayerLocation, CurrentLocation) < followRange)
		return true;
	return false;
}

void AAlienPet::FollowPlayer(float DeltaTime)
{
	timeSinceInRange += DeltaTime;

	if (!IsInRange())
	{
		timeSinceInRange = 0.f;
		SetActorLocation(PlayerLocation, true);

		BaseMesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
		return;
	}

	SetActorLocation(CurrentLocation + (PlayerLocation - CurrentLocation) * Speed, true);
}

void AAlienPet::RandomPlaySound(float DeltaTime)
{
	timeSinceLastNoise += DeltaTime;

	if (timeSinceLastNoise >= minTimeBetweenNoises)
	{
		if (rand() % inverseSoundProbablity < 2)
		{
			timeSinceLastNoise = 0.f;
			UGameplayStatics::PlaySoundAtLocation(this, sound, GetActorLocation(), GetActorRotation());
		}
	}
}
