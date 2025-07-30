// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/DamageInstigatorInterface.h"

#include "Tower.generated.h"


UCLASS()
class TOWERDEFENSE_API ATower :
	public AActor,
	public IDamageInstigatorInterface
{
	GENERATED_BODY()
	
public:
	ATower();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	//~ Begin IDamageInstigatorInterface override
public:
	virtual float GetDamage(UEntityComponent* InDamagedEntity) const override;
	//~ End   IDamageInstigatorInterface override

protected:
	UPROPERTY(EditInstanceOnly, Category = "Components")
	TObjectPtr<USceneComponent> Root;

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	float Damage = 1.f;

};
