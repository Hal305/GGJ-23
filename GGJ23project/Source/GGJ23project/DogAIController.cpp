// Fill out your copyright notice in the Description page of Project Settings.


#include "DogAIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "PlayerCharacter.h"

ADogAIController::ADogAIController()
{
	DogBTC = CreateDefaultSubobject<UBehaviorTreeComponent>("Dog BT Component");
	DogBB = CreateDefaultSubobject<UBlackboardComponent>("Dog BB Component");
}

void ADogAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	player = Cast<APlayerCharacter>(InPawn);
	DogBB->InitializeBlackboard(*DogBT->BlackboardAsset);
	DogBTC->StartTree(*DogBT);

	DogBB->SetValueAsObject("Player", player);
}

void ADogAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(player)
	{
		DogBB->SetValueAsBool("Player has scissor", player->bHasScissors);
		DogBB->SetValueAsBool("Interact Pressed", bInteractPressed);
	}
}
