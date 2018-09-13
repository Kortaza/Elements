// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_ElementsGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

AVR_ElementsGameModeBase::AVR_ElementsGameModeBase()
	: Super()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprint/Characters/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}



