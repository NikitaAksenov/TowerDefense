// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "HealthComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepleted);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

protected:
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	float MaxHealth = 0.f;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Runtime")
	float CurrentHealth = 0.f;

public:
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthDepleted OnHealthDepletedDelegate;

public:
	UFUNCTION(BlueprintCallable, Category = "Health")
	void Damage(float InDamage);

	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float IsHealthDepleted() const { return FMath::IsNearlyZero(CurrentHealth); }
	
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

protected:
	UFUNCTION(BlueprintCallable, Category = "Health")
	void ChangeHealth(float InDelta);

	UFUNCTION(CallInEditor, Category = "Runtime")
	void ApplySingleDamage();
	
	UFUNCTION(CallInEditor, Category = "Runtime")
	void ApplyMortalDamage();
};
