// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TowerProjectile.generated.h"


UCLASS()
class TOWERDEFENSE_API ATowerProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	ATowerProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
