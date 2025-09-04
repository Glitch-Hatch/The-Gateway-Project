#pragma once
#include "DataTypes/BoxSize.h"

USTRUCT(BlueprintType)
struct FDeliveryElementConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DisplayName = TEXT("Unnamed Item");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint ArrivalPriority = 0;

	UPROPERTY(editAnywhere, BlueprintReadWrite)
	EBoxSize Size = EBoxSize::Single;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint TotalAmount = 5;
};
