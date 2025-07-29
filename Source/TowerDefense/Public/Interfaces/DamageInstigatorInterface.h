// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "DamageInstigatorInterface.generated.h"


class UEntityComponent;


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageInstigatorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TOWERDEFENSE_API IDamageInstigatorInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual float GetDamage(UEntityComponent* InDamagedEntity) const = 0;
};
