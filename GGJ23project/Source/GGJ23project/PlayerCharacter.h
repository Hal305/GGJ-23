// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractPressed);

UCLASS()
class GGJ23PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		class USpringArmComponent* SpringArmComp = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		class UCameraComponent* CameraComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
		float Speed = 5.f;

	TSubclassOf<class UUserWidget> PauseWidget;

	UPROPERTY(BlueprintReadOnly)
		bool bFacingCam = true;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasScissors{ true };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasToy{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasPinecone{ false };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasFlashlight
	{ false };

	UPROPERTY(BlueprintAssignable)
		FOnInteractPressed InteractButtonPressed;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> PauseMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> HUD;
	*/

private:
	FVector SetLocation = FVector::ZeroVector;

	
	void MoveUp(float Value);
	void MoveSide(float Value);
	void Interact();

	

};
