// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Initialize the Camera Boom    
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	//Setup Camera Boom attachment to the Root component of the class
	SpringArm->SetupAttachment(RootComponent);

	//Set the boolean to use the PawnControlRotation to true.
	SpringArm->bUsePawnControlRotation = false;

	//Initialize the FollowCamera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));

	//Set FollowCamera attachment to the Camera Boom
	Camera->SetupAttachment(SpringArm);


}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerPawn::MoveSide);
}

void APlayerPawn::MoveUp(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		const FVector Direction = {1,0,0};
		AddMovementInput(Direction, AxisValue);
	}
}

void APlayerPawn::MoveSide(float AxisValue)
{
	if ((Controller != nullptr) && (AxisValue != 0.0f))
	{
		const FVector Direction = {0,1,0};
		AddMovementInput(Direction, AxisValue);
	}
}

