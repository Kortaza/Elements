// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElementOrb.generated.h"

UENUM(Blueprintable)
enum class EElementType : uint8
{
	FIRE		UMETA(DisplayName = "Fire"),
	EARTH		UMETA(DisplayName = "Earth"),
	WATER		UMETA(DisplayName = "Water"),	
	AIR			UMETA(DisplayName = "Air"),
};

UCLASS()
class VR_ELEMENTS_API AElementOrb : public AActor
{
	GENERATED_BODY()
	
public:		// Functionality
	AElementOrb();
	virtual void Tick(float DeltaTime) override;

protected:	// Functionality
	virtual void BeginPlay() override;

public:		// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USceneComponent* Origin;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Mesh_Orb;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Elemental Properties")
		EElementType Element;
	
protected:	// Variables
	
	
};
