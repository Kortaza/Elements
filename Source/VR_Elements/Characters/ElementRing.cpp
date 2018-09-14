// Fill out your copyright notice in the Description page of Project Settings.

#include "ElementRing.h"


// Sets default values
AElementRing::AElementRing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called every frame
void AElementRing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AElementRing::DestroyOrbs()
{
	unsigned int count = ElementOrbs.Num();
	for (unsigned int i = 0; i < count; i++)
	{
		ElementOrbs[i]->Destroy();
	}
}

// Called when the game starts or when spawned
void AElementRing::BeginPlay()
{
	Super::BeginPlay();

	FVector UpVec = GetActorUpVector();
	unsigned int count = SpawnOrder.Num();
	float radius = 30.0f;
	if (count > 0)
	{
		unsigned int degreeSpacing = 360 / count;
		for (unsigned int i = 0; i < count; i++)
		{
			//FVector::RotateAngleAxis
			FVector rotDir = UpVec.RotateAngleAxis(i * degreeSpacing, GetActorForwardVector());
			FVector spawnLoc = rotDir * radius + GetActorLocation();
			FRotator spawnRot = GetActorRotation();

			UWorld* world = GetWorld();
			if (world)
			{
				AElementOrb* orb = world->SpawnActor<AElementOrb>(SpawnOrder[i], spawnLoc, spawnRot);
				ElementOrbs.Add(orb);
			}
		}
	}
}



