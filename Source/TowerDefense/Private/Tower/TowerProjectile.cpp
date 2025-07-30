// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower/TowerProjectile.h"


ATowerProjectile::ATowerProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATowerProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATowerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

