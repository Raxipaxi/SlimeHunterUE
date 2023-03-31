// Fill out your copyright notice in the Description page of Project Settings.


#include "Hunter.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AHunter::AHunter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHunter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHunter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHunter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AHunter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AHunter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AHunter::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"),IE_Pressed,this,&AHunter::Shoot);

}

void AHunter::MoveForward(float Value)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
	AddActorLocalOffset(DeltaLocation,true);
}
void AHunter::MoveRight(float Value)
{
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.Z = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
	AddActorLocalOffset(DeltaLocation,true);
}

void AHunter::Turn(float Value)
{
}

void AHunter::Shoot()
{
}

