// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DayProgressorWidget.h"
#include "GameFramework/Actor.h"
#include "DayCycleRunner.generated.h"

UCLASS()
class THE_GATEWAY_PROJECT_API ADayCycleRunner : public AActor
{
	GENERATED_BODY()

	UPROPERTY(BlueprintGetter=GetDayCount)
	int DayCount = 0;
	
public:	
	// Sets default values for this actor's properties
	ADayCycleRunner();

	UFUNCTION(BlueprintCallable)
	void ProgressDaySequence(int DayProgressorIndex);

	UFUNCTION(BlueprintCallable)
	void ProgressDayInstantly();

	UFUNCTION(BlueprintPure)
	int GetDayCount() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UDayProgressorWidget>> DayProgressors;

	UFUNCTION(BlueprintCallable)
	virtual void OnDayChange() {}

	UFUNCTION(BlueprintCallable)
	virtual void OnTransitionFinish() {}
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
