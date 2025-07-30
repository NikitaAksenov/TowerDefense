// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Interfaces/DamageInstigatorInterface.h"

#include "Enemy.generated.h"


class UHealthComponent;
class USplineMovementComponent;


UCLASS()
class TOWERDEFENSE_API AEnemy :
	public AActor,
	public IDamageInstigatorInterface
{
	GENERATED_BODY()
	
public:
	AEnemy();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	
	//~ Begin IDamageInstigatorInterface override
public:
	virtual float GetDamage(UEntityComponent* InDamagedEntity) const override;
	//~ End   IDamageInstigatorInterface override


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> Root;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UHealthComponent> Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UEntityComponent> Entity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USplineMovementComponent> SplineMovement;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float Damage = 1.f;

public:
	UFUNCTION(BlueprintPure, Category = "Enemy")
	FORCEINLINE UHealthComponent* GetHealthComponent() const { return Health.Get(); }

	UFUNCTION(BlueprintPure, Category = "Enemy")
	FORCEINLINE UEntityComponent* GetEntityComponent() const { return Entity.Get(); }

protected:
	UFUNCTION()
	void OnHealthDepleted();
};
