// Fill out your copyright notice in the Description page of Project Settings.


#include "Heart/Heart.h"

#include "Components/EntityComponent.h"
#include "Components/HealthComponent.h"
#include "Components/SphereComponent.h"
#include "Enemy/Enemy.h"
#include "Interfaces/DamageInstigatorInterface.h"


AHeart::AHeart()
{
	PrimaryActorTick.bCanEverTick = true;

	// Scene components
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
	
	EnemyCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("EnemyCollisionSphere"));
	EnemyCollisionSphere->SetupAttachment(Root);

	// Actor components
	Health = CreateDefaultSubobject<UHealthComponent>("Health");

	Entity = CreateDefaultSubobject<UEntityComponent>(TEXT("Entity"));
}

void AHeart::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GetWorld()->IsGameWorld())
	{
		EnemyCollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnEnemyCollisionSphereBeginOverlap);
	}
}

void AHeart::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHeart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeart::OnEnemyCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (const IDamageInstigatorInterface* DamageInstigator = Cast<IDamageInstigatorInterface>(OtherActor))
	{
		const float Damage = DamageInstigator->GetDamage(GetEntityComponent());
		GetHealthComponent()->Damage(Damage);

		if (AEnemy* Enemy = Cast<AEnemy>(OtherActor))
		{
			Enemy->OnDamagedHeart();
		}
	}
}