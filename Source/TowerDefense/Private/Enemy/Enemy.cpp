// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/Enemy.h"

#include "Components/EntityComponent.h"
#include "Components/HealthComponent.h"
#include "SplineMovement/SplineMovementComponent.h"


AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	// Scene components
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	// Actor components
	Health = CreateDefaultSubobject<UHealthComponent>("Health");

	Entity = CreateDefaultSubobject<UEntityComponent>("Entity");

	SplineMovement = CreateDefaultSubobject<USplineMovementComponent>("SplineMovement");
}

void AEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	GetHealthComponent()->OnHealthDepletedDelegate.AddDynamic(this, &ThisClass::OnHealthDepleted);
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

void AEnemy::OnHealthDepleted()
{
	Destroy();
}
