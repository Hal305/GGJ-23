// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "GameFramework/PlayerInput.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initialising
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmCompComp"));
	SpringArmComp->SetupAttachment(PlayerMesh);
	SpringArmComp->bDoCollisionTest = false;
	SpringArmComp->SetUsingAbsoluteRotation(true);
	SpringArmComp->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArmComp->TargetArmLength = 225.f;
	SpringArmComp->bEnableCameraLag = false;
	SpringArmComp->CameraLagSpeed = 5.f;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComp->bUsePawnControlRotation = false;
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	
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
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPawn::MoveUp);
	PlayerInputComponent->BindAxis("MoveSide", this, &APlayerPawn::MoveSide);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerPawn::Interact);
}

void APlayerPawn::MoveUp(float Value)
{
	RootComponent->AddRelativeLocation(FVector(Value, 0, 0.f) * Speed);
}

void APlayerPawn::MoveSide(float Value)
{
	RootComponent->AddRelativeLocation(FVector(0, Value, 0.f) * Speed);
}

void APlayerPawn::Interact()
{
	// if((GetActorLocation() - NPC->GetActorLocation()).Size() < NPC->radius)
	// 	;
}

