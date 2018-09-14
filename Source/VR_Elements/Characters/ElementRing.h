// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ElementOrb.h"

#include "ElementRing.generated.h"

UCLASS()
class VR_ELEMENTS_API AElementRing : public AActor
{
	GENERATED_BODY()
	
public:		// Functionality
	AElementRing();
	virtual void Tick(float DeltaTime) override;
	void DestroyOrbs();

protected:	// Functionality
	virtual void BeginPlay() override;

public:		// Variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Element Spawn Options")
		TArray<TSubclassOf<AElementOrb>> SpawnOrder;

	
protected:	// Variables
	TArray<AElementOrb*> ElementOrbs;
	
};
