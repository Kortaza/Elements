// Fill out your copyright notice in the Description page of Project Settings.

#include "Controller_VR.h"



// Sets default values
AController_VR::AController_VR(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Default origin component
	Origin = CreateDefaultSubobject<USceneComponent>(TEXT("Origin"));
	Origin->SetupAttachment(RootComponent);

	// Create the static mesh component
	Mesh_Controller = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Controller"));
	Mesh_Controller->SetupAttachment(Origin);
}

// Called every frame
void AController_VR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AController_VR::SetCameraVR(UCameraComponent* cam)
{
	CameraVRRef = cam;
}

void AController_VR::SetHandType(EControllerHand type)
{
	HandType = type;
}

void AController_VR::SpawnElements()
{
	UWorld* world = GetWorld();
	if (world)
	{
		FVector spawnLoc = CameraVRRef->GetComponentLocation() + (100.0f * CameraVRRef->GetForwardVector());
		FRotator spawnRot = CameraVRRef->GetComponentRotation();
		ElementRing = (AElementRing*)world->SpawnActor<AElementRing>(Template_ElementRing, spawnLoc, spawnRot);
	}
}

void AController_VR::ReleaseElements()
{
	if (ElementRing)
	{
		ElementRing->DestroyOrbs();
		ElementRing->Destroy();
		ElementRing = 0;
	}
}

// Called when the game starts or when spawned
void AController_VR::BeginPlay()
{
	Super::BeginPlay();
	
}



