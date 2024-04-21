// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Respawnable.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class NORDICGAMEJAM24_API URespawnable : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	URespawnable();

	UPROPERTY(VisibleAnyWhere)
	FVector respawnLocation;

	UFUNCTION(BlueprintCallable)
	void Respawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
