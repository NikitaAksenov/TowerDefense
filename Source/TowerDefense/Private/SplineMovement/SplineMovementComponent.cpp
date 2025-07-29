// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineMovement/SplineMovementComponent.h"

#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SplineMovement/SplineMovementRoad.h"


USplineMovementComponent::USplineMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USplineMovementComponent::BeginPlay()
{
	Super::BeginPlay();

}

void USplineMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsMoving())
	{
		if (!Road.IsValid())
		{
			StopMoving();
		}
		else
		{
			const float DeltaDistance = Speed * DeltaTime;

			const float NewDistance = CurrentDistanceOnSpline + DeltaDistance;
		 	
			const FVector NewLocation = Road->GetSpline()->GetLocationAtDistanceAlongSpline(NewDistance, ESplineCoordinateSpace::World);

			GetOwner()->SetActorLocation(NewLocation);

			CurrentDistanceOnSpline = NewDistance;

			const float SplineLength = Road->GetSpline()->GetSplineLength();
			if (CurrentDistanceOnSpline > SplineLength)
			{
				StopMoving();
			}
		}
	}
}

void USplineMovementComponent::StartMoving()
{
	if (IsMoving()) return;
	
	if (!Road.IsValid())
	{
		if (ASplineMovementRoad* FoundRoad = FindRoad())
		{
			Road = FoundRoad;
		}
		else
		{
			return;
		}
	}

	bMoving = true;	
}

void USplineMovementComponent::StopMoving()
{
	if (!IsMoving()) return;

	bMoving = false;
}

ASplineMovementRoad* USplineMovementComponent::FindRoad() const
{
	return Cast<ASplineMovementRoad>(UGameplayStatics::GetActorOfClass(this, ASplineMovementRoad::StaticClass()));
}

