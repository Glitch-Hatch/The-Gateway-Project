#pragma once

UENUM(BlueprintType)
enum class EBoxSize: uint8
{
	Small = 0 UMETA(DisplayName = "Small", ToolTip = "Small (x1/2)"),
	Single = 1 UMETA(DisplayName = "Single", ToolTip = "Single (x1)"),
	Double = 2 UMETA(DisplayName = "Double", ToolTip = "Double (x2)"),
	Quadruple = 4 UMETA(DisplayName = "Quadruple", ToolTip = "Quadruple (x4)"),
	Sextuple = 6 UMETA(DisplayName = "Sextuple", ToolTip = "Sextuple (x6)"),
	Octuple = 8 UMETA(DisplayName = "Octuple", ToolTip = "Octuple (x8)"),
	Decuple = 10 UMETA(DisplayName = "Decuple", ToolTip = "Decuple (x10)"),
};
