// Fill out your copyright notice in the Description page of Project Settings.

#include "Platforms.h"
#include "math.h"

// #define PI 3.141592653589793238462643383279502884197

// Sets default values for this component's properties
UPlatforms::UPlatforms()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UPlatforms::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UPlatforms::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (moves)
		this->MovePlatform(DeltaTime);
}

float UPlatforms::SinIntegralRange(float lower, float upper)
{
	return (cos(upper / roundTripTime * PI * 2) - cos(lower / roundTripTime * PI * 2)) / 2;
}

void UPlatforms::MovePlatform(float DeltaTime)
{
	GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + moveVector * SinIntegralRange(timeSinceSpawn, timeSinceSpawn + DeltaTime));

	timeSinceSpawn += DeltaTime;
}
