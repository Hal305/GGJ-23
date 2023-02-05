// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialising
//	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompComp"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bDoCollisionTest = false;
	SpringArmComp->SetUsingAbsoluteRotation(true);
	SpringArmComp->SetRelativeRotation(FRotator(-25.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 225.f;
	SpringArmComp->bEnableCameraLag = false;
	SpringArmComp->CameraLagSpeed = 5.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComp->bUsePawnControlRotation = false;
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerCharacter::MoveSide);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
}

void APlayerCharacter::MoveUp(float Value)
{
	if (Value > 0.01)
		bFacingCam = false;
	if (Value < -0.01)
		bFacingCam = true;
	if(Value > 0.01 || Value < -0.01)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APlayerCharacter::MoveSide(float Value)
{
	if (Value > 0.01 || Value < -0.01)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void APlayerCharacter::Interact()
{
	InteractButtonPressed.Broadcast();
}

