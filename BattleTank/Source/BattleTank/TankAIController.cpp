// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"






void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	
	{
		UE_LOG(LogTemp, Error, TEXT("AI cannot PosessTank"));
	}
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ControlledTank = Cast<ATank>(GetPawn());

}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (PlayerTank) {
		//TODO MoveTwardsPlayer
		AimAtPlayer();

		//TODO FireIfReady
		ControlledTank->Fire();
	}
	
}

void ATankAIController::AimAtPlayer()
{	
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
}

