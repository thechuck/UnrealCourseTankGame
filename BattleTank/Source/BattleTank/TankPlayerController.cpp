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
		GetControlledTank()->AimAt(HitLocation);
	}

	//get world location if linetrace through crosshair
	//if it hits the landscape
		//tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position in pixel coordinates.
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	//de-project the screen position of the crosshair to a world direciton
	FVector LookDirection;
	if(GetLookLocation(ScreenLocation, LookDirection))
	{
		//line-trace along that look direciton, see what we hit up to max range.
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
	
	
	return true;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult LineHitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	

	if (GetWorld()->LineTraceSingleByChannel(
		LineHitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility)) {
		HitLocation = LineHitResult.Location;
		return (true);
	}
	else {
		HitLocation = FVector(0);
		return false;
	}
}

bool ATankPlayerController::GetLookLocation(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraLocation,
		LookDirection);
}