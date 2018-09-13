// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Controller_VR.generated.h"

UCLASS()
class VR_ELEMENTS_API AController_VR : public AActor
{
	GENERATED_BODY()

public:		// Functionality
	AController_VR(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void Tick(float DeltaTime) override;
	void SetHandType(EControllerHand type);

protected:	// Functionality
	virtual void BeginPlay() override;

public:		// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh_Controller;

protected:	// Variables
	EControllerHand HandType;



};
