// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"






void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("AI cannot PosessTank"));
	}
	


}
void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank()) {

		//TODO MoveTwardsPlayer
		AimAtPlayer();
		//TODO FireIfReady
	}
}

ATank*  ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) 
	{
		return nullptr;
	}
	return(Cast<ATank>(PlayerTank));
}

void ATankAIController::AimAtPlayer()
{	
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}

