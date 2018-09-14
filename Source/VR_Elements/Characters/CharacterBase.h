// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Controller_VR.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"



UCLASS()
class VR_ELEMENTS_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:		// Functionality
	ACharacterBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:	// Functionality
	virtual void BeginPlay() override;

	// Inputs
	void SpawnElements_Pressed();
	void SpawnElements_Released();
	
public:		// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* VR_Origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* VR_Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* MotionController_Left;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UMotionControllerComponent* MotionController_Right;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AController_VR> Template_VR_Controller;

protected:	// Variables
	AController_VR* ControllerVR_Left;
	AController_VR* ControllerVR_Right;
};
