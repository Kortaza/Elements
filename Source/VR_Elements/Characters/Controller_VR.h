// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ElementRing.h"

#include "Controller_VR.generated.h"

UCLASS()
class VR_ELEMENTS_API AController_VR : public AActor
{
	GENERATED_BODY()

public:		// Functionality
	AController_VR(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void Tick(float DeltaTime) override;
	void SetCameraVR(UCameraComponent* cam);
	void SetHandType(EControllerHand type);
	void SpawnElements();
	void ReleaseElements();

protected:	// Functionality
	virtual void BeginPlay() override;

public:		// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh_Controller;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Templates")
		TSubclassOf<AElementRing> Template_ElementRing;

protected:	// Variables
	EControllerHand HandType;
	UCameraComponent* CameraVRRef;
	AElementRing* ElementRing;


};
