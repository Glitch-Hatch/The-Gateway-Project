#pragma once
#include "BoxDeliveryOutline.h"
#include "BoxDeliveryDay.generated.h"

USTRUCT(BlueprintType)
struct FBoxDeliveryDay
{
	GENERATED_USTRUCT_BODY()

	FBoxDeliveryDay() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDeliveryElementConfig> Value;
};
