// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{	
		UE_LOG(LogTemp, Warning, TEXT("Posessing %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("No pawn possessed"));
	}

}


ATank*  ATankPlayerController::GetControlledTank() const
{	
		return Cast<ATank>(GetPawn());	
}