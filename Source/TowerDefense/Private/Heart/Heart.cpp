// Fill out your copyright notice in the Description page of Project Settings.


#include "Heart/Heart.h"


AHeart::AHeart()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
}

void AHeart::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHeart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
