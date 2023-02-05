// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DogAIController.generated.h"

/**
 * 
 */
UCLASS()
class GGJ23PROJECT_API ADogAIController : public AAIController
{
	GENERATED_BODY()
public:
	ADogAIController();
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite)
		bool bInteractPressed;
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* DogBT;
	class UBehaviorTreeComponent* DogBTC;
	class UBlackboardComponent* DogBB;
	class APlayerCharacter* player;
};
