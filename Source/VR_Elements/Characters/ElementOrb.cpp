// Fill out your copyright notice in the Description page of Project Settings.

#include "ElementOrb.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AElementOrb::AElementOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Origin component for the actor
	Origin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));
	Origin->SetupAttachment(RootComponent);

	// Create the Mesh for the Element Orb
	static ConstructorHelpers::FObjectFinder<UStaticMesh>OrbMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	Mesh_Orb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Orb"));
	Mesh_Orb->SetStaticMesh(OrbMesh.Object);
	Mesh_Orb->SetupAttachment(Origin);
}

// Called every frame
void AElementOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when the game starts or when spawned
void AElementOrb::BeginPlay()
{
	Super::BeginPlay();
	Mesh_Orb->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
}



