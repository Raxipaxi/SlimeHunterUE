// Fill out your copyright notice in the Description page of Project Settings.


#include "Hunter.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHunter::AHunter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	WeaponMesh->SetupAttachment(BaseMesh);
	
	SpawnPoint  = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	SpawnPoint->SetupAttachment(WeaponMesh);

}

// Called when the game starts or when spawned
void AHunter::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerPtr = Cast<APlayerController>(GetController());
	
}

// Called every frame
void AHunter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerControllerPtr)
	{
		FHitResult HitResult;
		PlayerControllerPtr->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
		Turn(HitResult.ImpactPoint);
	}

}

// Called to bind functionality to input
void AHunter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AHunter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AHunter::MoveRight);
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
	DeltaLocation.Y = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	
	AddActorLocalOffset(DeltaLocation,true);
}

void AHunter::Turn(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - BaseMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f,ToTarget.Rotation().Yaw,0.f);

	BaseMesh->SetWorldRotation(FMath::RInterpTo(BaseMesh->GetComponentRotation(),LookAtRotation,UGameplayStatics::GetWorldDeltaSeconds(this),25.f));
}

void AHunter::Shoot()
{
	
}

