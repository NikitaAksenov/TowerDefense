// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"

#include "Components/HealthComponent.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	// Scene components
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	// Actor components
	Health = CreateDefaultSubobject<UHealthComponent>("Health");
}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AEnemy::GetDamage(UEntityComponent* InDamagedEntity) const
{
	return Damage;
}

