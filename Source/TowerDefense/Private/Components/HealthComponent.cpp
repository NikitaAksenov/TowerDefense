// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"


UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;
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
	CurrentHealth = FMath::Clamp(CurrentHealth + InDelta, 0.f, GetMaxHealth());

	if (IsHealthDepleted())
	{
		OnHealthDepletedDelegate.Broadcast();
	}
}

void UHealthComponent::ApplySingleDamage()
{
	Damage(1.f);
}

void UHealthComponent::ApplyMortalDamage()
{
	Damage(GetMaxHealth());
}
