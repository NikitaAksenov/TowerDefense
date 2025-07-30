// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower/Tower.h"


ATower::ATower()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ATower::GetDamage(UEntityComponent* InDamagedEntity) const
{
	return Damage;
}

