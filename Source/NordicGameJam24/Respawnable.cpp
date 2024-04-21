// Fill out your copyright notice in the Description page of Project Settings.

#include "Respawnable.h"

// Sets default values
URespawnable::URespawnable()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void URespawnable::BeginPlay()
{
	Super::BeginPlay();
	respawnLocation = GetOwner()->GetActorLocation();
}

// Called every frame
void URespawnable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void URespawnable::Respawn()
{
	GetOwner()->SetActorLocation(respawnLocation);
}