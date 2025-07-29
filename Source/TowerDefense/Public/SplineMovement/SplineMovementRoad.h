// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SplineMovementRoad.generated.h"


class USplineComponent;


UCLASS()
class TOWERDEFENSE_API ASplineMovementRoad : public AActor
{
	GENERATED_BODY()
	
public:
	ASplineMovementRoad();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USplineComponent> Spline;

public:
	UFUNCTION(BlueprintPure, Category = "SplineMovementRoad")
	FORCEINLINE USplineComponent* GetSpline() const { return Spline; }
};
