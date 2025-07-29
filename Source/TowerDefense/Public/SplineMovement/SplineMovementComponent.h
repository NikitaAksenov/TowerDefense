// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SplineMovementComponent.generated.h"


class ASplineMovementRoad;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API USplineMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USplineMovementComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	TWeakObjectPtr<ASplineMovementRoad> Road;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	bool bMoving = false;
	
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	float CurrentDistanceOnSpline = 0.f;

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	float Speed = 100.f;

public:
	UFUNCTION(BlueprintCallable, Category = "SplineMovement")
	void StartMoving();

	UFUNCTION(BlueprintCallable, Category = "SplineMovement")
	void StopMoving();
	
	UFUNCTION(BlueprintCallable, Category = "SplineMovement")
	FORCEINLINE bool IsMoving() const { return bMoving; }

	ASplineMovementRoad* FindRoad() const;
};
