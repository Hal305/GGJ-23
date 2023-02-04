// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMesh")
	USkeletalMeshComponent* PlayerMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMesh")
	USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMesh")
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerMesh")
	float Speed = 5.f;

private:
	FVector SetLocation = FVector::ZeroVector;
	
	void MoveUp(float Value);
	void MoveSide(float Value);

};
