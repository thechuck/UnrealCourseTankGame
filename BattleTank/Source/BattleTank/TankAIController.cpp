// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"






void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetPlayerTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI found player %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No pawn possessed"));
	}

}


ATank*  ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController();
	if (PlayerTank) 
	{
		return(Cast<ATank>(PlayerTank));
	}
	else {
		return nullptr;
	}
}