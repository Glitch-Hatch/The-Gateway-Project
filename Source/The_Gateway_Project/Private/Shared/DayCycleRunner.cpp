// Fill out your copyright notice in the Description page of Project Settings.


#include "Shared/DayCycleRunner.h"

#include "GatewayConfiguration.h"

// Sets default values
ADayCycleRunner::ADayCycleRunner()
{
	PrimaryActorTick.bCanEverTick = true;

	// This doesn't do anything, Rider just thinks that I forgot to initialize
	// a subobject. It's right but the DayCycleSystem often lets ActiveProgressor
	// be undefined, especially at construction.
	ActiveProgressor = nullptr;
}

void ADayCycleRunner::BeginPlay()
{
	Super::BeginPlay();

	// Temp
	ProgressDaySequence(1);
}

void ADayCycleRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ActiveProgressor != nullptr)
	{
		ActiveProgressor->OnTick(DeltaTime);

		if (ActiveProgressor->TransitionFinalized && !LocalFinalizedTransition)
		{
			LocalFinalizedTransition = true;
			ProgressDayInstantly();
			ActiveProgressor->OnParentRecognizedTransitionFinished();

			if (ActiveProgressor->ResetDaysOnComplete)
			{
				UE_LOG(GWLogDayChange, Display, TEXT("Day count reset from %d"), DayCount)
				DayCount = 0;
			}
		}
		
		if (ActiveProgressor->TransitionProgress >= 1)
		{
			RemoveActiveProgressor();
		}
	}
}

void ADayCycleRunner::ProgressDayInstantly()
{
	OnTransitionFinish();
	DayCount++;
}

void ADayCycleRunner::RemoveActiveProgressor()
{
	if (ActiveProgressor != nullptr)
	{
		if (!ActiveProgressor->TransitionFinalized)
		{
			auto completionPercent = FMath::RoundToFloat(ActiveProgressor->TransitionProgress*100);
			UE_LOG(GWLogDayChange, Display, TEXT("Transition removed without running FinalizeTransition. Progress: %f percent"), completionPercent)
		}

		ActiveProgressor->OnDestroyAnyReason();
		ActiveProgressor->MarkAsGarbage();
		ActiveProgressor = nullptr;
		LocalFinalizedTransition = false;
	}
	else
	{
		UE_LOG(GWLogDayChange, Display, TEXT("ActiceProgressor already empty."))
	}
}

void ADayCycleRunner::ProgressDaySequence(int DayProgressorIndex)
{
	if (!DayProgressors.IsValidIndex(DayProgressorIndex))
	{
		const auto progressorListLen = DayProgressors.Num();
		UE_LOG(GWLogDayChange, Error, TEXT("Missing index for DayProgressors. (tried: %d, availible: %d)"), DayProgressorIndex, progressorListLen)
		if (progressorListLen == 0)
		{
			UE_LOG(GWLogDayChange, Error, TEXT("CHECK WHETHER \"DayCycleRunner.DayProgressors\" IS EMPTY!"));
		}
		return;
	}

	if (ActiveProgressor == nullptr)
	{
		UE_LOG(GWLogDayChange, Warning, TEXT("Progressor already active. Try RemoveActiveProgressor to cancel a day cycle."))
		return;
	}

	LocalFinalizedTransition = false;
	ActiveProgressor = DayProgressors[DayProgressorIndex].GetDefaultObject();
}

int ADayCycleRunner::GetDayCount() const
{
	return DayCount;
}

