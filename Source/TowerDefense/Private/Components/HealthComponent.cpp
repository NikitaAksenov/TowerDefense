// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"


UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UHealthComponent::InitializeComponent()
{
	Super::InitializeComponent();

	CurrentHealth = MaxHealth;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UHealthComponent::Damage(float InDamage)
{
	if (IsHealthDepleted()) return;

	ChangeHealth(-InDamage);
}

void UHealthComponent::ChangeHealth(float InDelta)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + InDelta, 0.f, MaxHealth);

	if (IsHealthDepleted())
	{
		OnHealthDepletedDelegate.Broadcast();
	}
}
