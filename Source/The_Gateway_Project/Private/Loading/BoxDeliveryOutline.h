#pragma once
#include "DeliveryElementConfig.h"
#include "BoxDeliveryOutline.generated.h"

USTRUCT(BlueprintType)
struct FBoxDeliveryOutline
{
	GENERATED_USTRUCT_BODY()

	FBoxDeliveryOutline() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FDeliveryElementConfig BoxType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount = 0;
};
