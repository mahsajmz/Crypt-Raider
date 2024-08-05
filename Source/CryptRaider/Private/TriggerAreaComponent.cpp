// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerAreaComponent.h"

UTriggerAreaComponent::UTriggerAreaComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
   
}

void UTriggerAreaComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UTriggerAreaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* HasActor = GetAcceptableActor();
    if (HasActor == nullptr)
    {   
        Mover->SetShouldMove(false);
    }
    else 
    {
        UE_LOG(LogTemp, Display, TEXT("should move!"));
        Mover->SetShouldMove(true);

    }



}

void UTriggerAreaComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}


AActor* UTriggerAreaComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for (AActor* Actor : Actors)
    {
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        bool IsGrabbed = Actor->ActorHasTag("Grabbed");
        if (HasAcceptableTag && !IsGrabbed)
        {
            UE_LOG(LogTemp, Display, TEXT("Actor Has Acceptable Tag"));
            return Actor;
        }
            
    } 
    return nullptr;
}

   
