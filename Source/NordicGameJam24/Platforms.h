// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Platforms.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class NORDICGAMEJAM24_API UPlatforms : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlatforms();

	UPROPERTY(EditAnywhere)
	bool moves = false;

	UPROPERTY(EditAnywhere)
	FVector moveVector = FVector(0, 0, 100);

	UPROPERTY(EditAnywhere)
	float roundTripTime = 10.f;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	float timeSinceSpawn = 0.0f;

	void MovePlatform(float DeltaTime);
	float SinIntegralRange(float lower, float upper);
};
