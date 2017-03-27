// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
    AimAtCrosshair();
}

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


//move tank barrel to point at crosshair so shot passes through crosshair.  
void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("hitlocation: %s"), *HitLocation.ToString());
	}

	//get world location if linetrace through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0f);
	return true;
}