// Copyright Epic Games, Inc. All Rights Reserved.

#include "assignment_1CGameMode.h"
#include "assignment_1CCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aassignment_1CGameMode::Aassignment_1CGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Script/Engine.Blueprint/Game/MyWhatisLove_BP.MyWhatisLove_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
