// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/EntityComponent.h"


UEntityComponent::UEntityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UEntityComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UEntityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

