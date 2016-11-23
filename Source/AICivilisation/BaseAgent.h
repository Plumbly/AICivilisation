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
	virtual bool CheckIsDead();
	
public:
	// Sets default values for this character's properties
	ABaseAgent();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(BlueprintReadWrite, Category = "Vision")
	float ViewDistance;
	UPROPERTY(BlueprintReadWrite, Category = "Vision")
	float FieldOFView;

	UFUNCTION(Category = "Vision")
	virtual void GetViewingArc();

	UPROPERTY(BlueprintReadWrite, Category="Status")
	float Health;
	UPROPERTY(BlueprintReadWrite, Category = "Status")
	float Energy;
	UPROPERTY(BlueprintReadOnly, Category = "Status")
	bool IsDead;

	UPROPERTY(BlueprintReadWrite, Category = "Information")
	float Age;

	float TimeAlive;

	UFUNCTION(BlueprintNativeEvent, Category = "Status")
	void OnDeath();

	UFUNCTION(BlueprintCallable, Category = "Status")
	virtual void TakeDamage(int32 dmg);
	
	UFUNCTION(BlueprintCallable, Category = "Status")
	virtual void Kill();

};
