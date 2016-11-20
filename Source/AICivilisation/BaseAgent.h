// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseAgent.generated.h"

UCLASS()
class AICIVILISATION_API ABaseAgent : public ACharacter
{
	GENERATED_BODY()

private:
	float TimeElapsed;
	float EnergyLossPerSecond;
	
public:
	// Sets default values for this character's properties
	ABaseAgent();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(BlueprintReadOnly, Category="Status")
	float Health;
	UPROPERTY(BlueprintReadOnly, Category = "Status")
	float Energy;
	UPROPERTY(BlueprintReadWrite, Category = "Information")
	float Age;

	float TimeAlive;

	virtual bool IsDead();
};
