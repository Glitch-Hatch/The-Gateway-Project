// Fill out your copyright notice in the Description page of Project Settings.


#include "Shared/DayCycleRunner.h"

// Sets default values
ADayCycleRunner::ADayCycleRunner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADayCycleRunner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADayCycleRunner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADayCycleRunner::ProgressDayInstantly()
{
	
}

void ADayCycleRunner::ProgressDaySequence(int DayProgressorIndex)
{
	
}



int ADayCycleRunner::GetDayCount() const
{
	return DayCount;
}

