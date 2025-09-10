// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DayCycleRunner.h"
#include "Blueprint/UserWidget.h"
#include "DayProgressorWidget.generated.h"

/**
 * 
 */
UCLASS()
class THE_GATEWAY_PROJECT_API UDayProgressorWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ADayCycleRunner* DayCycleRunner;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool TransitionFinalized;

	UPROPERTY()
	bool AccountedTransition;
	
	UFUNCTION(BlueprintCallable)
	void FinalizeSequence();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TransitionDuration = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TransitionProgress = 0;
};
