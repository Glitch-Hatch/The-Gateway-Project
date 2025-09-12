#pragma once
#include "DataTypes/BoxShape.h"
#include "DataTypes/BoxSize.h"
#include "DeliveryElementConfig.generated.h"

USTRUCT(BlueprintType)
struct FDeliveryElementConfig: public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FDeliveryElementConfig() {}
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DisplayName = TEXT("Unnamed Item");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ArrivalPriority = 0;

	UPROPERTY(editAnywhere, BlueprintReadWrite)
	EBoxSize Size = EBoxSize::Single;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBoxShape Shape = EBoxShape::ArcDeep;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalAmount = 5;

	UPROPERTY()
	int SentAmount = 0;
};
