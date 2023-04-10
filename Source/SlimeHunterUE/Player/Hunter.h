// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Hunter.generated.h"

class AGun;
UCLASS()
class SLIMEHUNTERUE_API AHunter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHunter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	APlayerController* PlayerControllerPtr;
	
	// Stats
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Stats", meta = (AllowPrivateAccess="true"))
	float Speed = 200.f;

	UPROPERTY(EditInstanceOnly,BlueprintReadWrite, Category="Stats", meta = (AllowPrivateAccess="true"))
	float TurnRate = 20.f;

	// Movement
	void MoveForward(float Value);
	void MoveRight(float Value); 
	void Turn(FVector Value);

	// Actions
	void Shoot();

	//Weapon
	UPROPERTY()
	AGun* Gun;
	
	

};


