// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "EnhancedInput/Public/InputMappingContext.h"

#include "TDPawn.generated.h"


class UCameraComponent;
class USpringArmComponent;


UCLASS()
class TOWERDEFENSE_API ATDPawn : public APawn
{
	GENERATED_BODY()

public:
	ATDPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCameraComponent> Camera;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings|Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;
};
