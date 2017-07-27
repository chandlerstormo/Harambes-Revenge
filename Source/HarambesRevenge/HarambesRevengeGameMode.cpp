// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "HarambesRevenge.h"
#include "HarambesRevengeGameMode.h"
#include "HarambesRevengeCharacter.h"

AHarambesRevengeGameMode::AHarambesRevengeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
