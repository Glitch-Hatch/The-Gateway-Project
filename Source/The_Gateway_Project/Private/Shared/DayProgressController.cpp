// Fill out your copyright notice in the Description page of Project Settings.


#include "Shared/DayProgressController.h"

void UDayProgressController::FinalizeSequence()
{
	OnPreTransitionFinished();
	TransitionFinalized = true;
}

void UDayProgressController::OnTick(float DeltaTime)
{
	TransitionProgress += DeltaTime/TransitionDuration;
}