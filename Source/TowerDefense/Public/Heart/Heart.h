// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Heart.generated.h"


class UEntityComponent;
class UHealthComponent;
class USphereComponent;


UCLASS()
class TOWERDEFENSE_API AHeart : public AActor
{
	GENERATED_BODY()
	
public:
	AHeart();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> EnemyCollisionSphere;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UHealthComponent> Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UEntityComponent> Entity;

public:
	UFUNCTION(BlueprintPure, Category = "Heart")
	FORCEINLINE UHealthComponent* GetHealthComponent() const { return Health.Get(); }
	
	UFUNCTION(BlueprintPure, Category = "Heart")
	FORCEINLINE UEntityComponent* GetEntityComponent() const { return Entity.Get(); }

protected:
	UFUNCTION()
	void OnEnemyCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
