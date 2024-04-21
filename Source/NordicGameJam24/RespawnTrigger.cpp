// Fill out your copyright notice in the Description page of Project Settings.

#include "RespawnTrigger.h"

ARespawnTrigger::ARespawnTrigger()
{
    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
    BoxCollider->GetScaledBoxExtent();
    BoxCollider->SetupAttachment(RootComponent);

    if (BoxCollider != nullptr)
        // Register Events
        BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ARespawnTrigger::OnOverlapBegin);
}

void ARespawnTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void ARespawnTrigger::OnOverlapBegin(UPrimitiveComponent *OverlappedComponent,
                                     AActor *OtherActor,
                                     UPrimitiveComponent *OtherComp,
                                     int32 OtherBodyIndex,
                                     bool bFromSweep,
                                     const FHitResult &SweepResult)
{
    if (OtherActor && OtherActor != this)
    {
        UE_LOG(LogTemp, Display, TEXT("Overlap Begin"));
        UE_LOG(LogTemp, Display, TEXT("Overlapped Actor = %s"), *OverlappedComponent->GetOwner()->GetName());

        if (URespawnable *respawnComponent = Cast<URespawnable>(OtherActor->GetComponentByClass(URespawnable::StaticClass())))
        {
            respawnComponent->Respawn();
        }
    }
}