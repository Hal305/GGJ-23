// Fill out your copyright notice in the Description page of Project Settings.


#include "FriendPawn.h"

// Sets default values
AFriendPawn::AFriendPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFriendPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFriendPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(found)
		FollowPlayer();
}

// Called to bind functionality to input
void AFriendPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFriendPawn::FollowPlayer()
{
	
}

void AFriendPawn::FoundByPlayer()
{
	found = true;
}
