// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"

// Unreal Functionality support
#include "Kismet/GameplayStatics.h"

// HMD and Motion Controller library support
#include "HeadMountedDisplayFunctionLibrary.h"
#include "MotionControllerComponent.h"
#include "XRMotionControllerBase.h"


// Sets default values
ACharacterBase::ACharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating the Base VR Origin and Camera
	VR_Origin = CreateDefaultSubobject<USceneComponent>(TEXT("VR_Origin"));
	VR_Origin->SetupAttachment(GetRootComponent());
	VR_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("VR_Camera"));
	VR_Camera->SetupAttachment(VR_Origin);

	// Creating the two motion controller components
	MotionController_Left = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController_Left"));
	MotionController_Left->MotionSource = FXRMotionControllerBase::LeftHandSourceId;
	MotionController_Left->SetupAttachment(RootComponent);
	
	MotionController_Right = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController_Right"));
	MotionController_Right->MotionSource = FXRMotionControllerBase::RightHandSourceId;
	MotionController_Right->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* world = GetWorld();
	if (world)
	{
		FAttachmentTransformRules attachmentRules(EAttachmentRule::KeepWorld, true);

		// Spawn and attach Left Hand
		FVector spawnLoc = MotionController_Left->GetComponentLocation();
		FRotator spawnRot = MotionController_Left->GetComponentRotation();
		ControllerVR_Left = (AController_VR*)world->SpawnActor(Template_VR_Controller, &spawnLoc, &spawnRot);
		ControllerVR_Left->AttachToComponent(MotionController_Left, attachmentRules);
		ControllerVR_Left->SetHandType(EControllerHand::Left);

		// Spawn and attach Weapon (Right Hand)
		spawnLoc = MotionController_Right->GetComponentLocation();
		spawnRot = MotionController_Right->GetComponentRotation();
		ControllerVR_Right = (AController_VR*)world->SpawnActor(Template_VR_Controller, &spawnLoc, &spawnRot);
		ControllerVR_Right->AttachToComponent(MotionController_Right, attachmentRules);
	}
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

