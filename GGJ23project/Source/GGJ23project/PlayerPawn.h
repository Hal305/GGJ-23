// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "FriendPawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class GGJ23PROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//new code
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	USceneComponent* PlayerMesh = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	USpringArmComponent* SpringArmComp = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	UCameraComponent* CameraComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Speed = 5.f;

	AFriendPawn* NPC = nullptr;

private:
	FVector SetLocation = FVector::ZeroVector;
	
	void MoveUp(float Value);
	void MoveSide(float Value);
	void Interact();
	
};
