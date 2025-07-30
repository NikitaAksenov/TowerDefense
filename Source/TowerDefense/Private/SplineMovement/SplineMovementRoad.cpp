// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineMovement/SplineMovementRoad.h"

#include "Components/SplineComponent.h"


ASplineMovementRoad::ASplineMovementRoad()
{
	PrimaryActorTick.bCanEverTick = true;

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	RootComponent = Spline;
}

void ASplineMovementRoad::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASplineMovementRoad::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

