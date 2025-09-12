// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../../Private/Loading/BoxDeliveryOutline.h"
#include "../../Private/Loading/BoxDeliveryDay.h"
#include "BoxDeliveryManager.generated.h"

UCLASS()
class THE_GATEWAY_PROJECT_API ABoxDeliveryManager : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY()
	USceneComponent* _RootComponent;

	UFUNCTION()
	TArray<FBoxDeliveryDay> InitializeBoxDistribution();

	UPROPERTY()
	TArray<FBoxDeliveryDay> BoxDistributionPattern;

	UFUNCTION()
	int GetOverallBoxCount(TArray<FDeliveryElementConfig> boxConfigs);

	UFUNCTION()
	TArray<FDeliveryElementConfig> GetDayOfBoxes(int totalBoxesOfDay, TArray<FDeliveryElementConfig> configs, TArray<int>& sentAmounts, bool getEverything);

	UPROPERTY()
	int RandomBoxRecursionCounter = 0;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* BoxDeliveryData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalDays = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SelectionPercentageBias = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ReverseBoxSelectionMethod = true;

	UPROPERTY(editAnywhere, BlueprintReadWrite)
	int RandomBoxRecursionBound = 1000;
	
protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	
	ABoxDeliveryManager();
};