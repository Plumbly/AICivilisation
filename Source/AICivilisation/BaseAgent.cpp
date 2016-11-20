// Fill out your copyright notice in the Description page of Project Settings.

#include "AICivilisation.h"
#include "BaseAgent.h"


// Sets default values
ABaseAgent::ABaseAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100;

	Energy = 100;

	Age = 20;

	TimeAlive = 0;

	TimeElapsed = 0;

	EnergyLossPerSecond = 1;
}

// Called when the game starts or when spawned
void ABaseAgent::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ABaseAgent::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	TimeElapsed += DeltaTime;

	TimeAlive += DeltaTime;

	if (TimeElapsed > 1) {
		TimeElapsed--;

		Energy -= EnergyLossPerSecond;
	}

	if (IsDead()) {

		//GetWorld()->DestroyActor(this);
	}
}

// Called to bind functionality to input
void ABaseAgent::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

bool ABaseAgent::IsDead(){
	return Health == 0 || Energy == 0;
}
