// Fill out your copyright notice in the Description page of Project Settings.


#include "Shared/DayProgressController.h"

void ADayProgressController::FinalizeSequence()
{
	OnPreTransitionFinished();
	TransitionFinalized = true;
}

void ADayProgressController::OnTick(float DeltaTime)
{
	TransitionProgress += DeltaTime/TransitionDuration;
}