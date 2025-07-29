// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameplayTagContainer.h"

#include "EntityComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOWERDEFENSE_API UEntityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UEntityComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	FGameplayTagContainer IdentityTags;

public:
	UFUNCTION(BlueprintPure, Category = "Entity")
	FORCEINLINE FGameplayTagContainer GetIdentityTags() const { return IdentityTags; }
};
