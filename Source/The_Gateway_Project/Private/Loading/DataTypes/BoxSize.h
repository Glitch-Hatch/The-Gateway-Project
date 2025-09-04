#pragma once

UENUM(BlueprintType)
enum class EBoxSize: uint8
{
	Small = 0 UMETA(DisplayName = "Small (x1/2)"),
	Single = 1 UMETA(DisplayName = "Single (x1)"),
	Double = 2 UMETA(DisplayName = "Double (x2)"),
	Quadruple = 4 UMETA(DisplayName = "Quadruple (x4)"),
	Sextuple = 6 UMETA(DisplayName = "Sextuple (x6)"),
	Octuple = 8 UMETA(DisplayName = "Octuple (x8)"),
	Decuple = 10 UMETA(DisplayName = "Decuple (x10)"),
};
