#pragma once

UENUM(BlueprintType)
enum class EBoxShape: uint8
{
	ArcDeep = 0 UMETA(DisplayName = "Arc Deep"),
	ThinDeep = 1 UMETA(DisplayName = "Thin Deep"),
	
	ArcSurface = 2 UMETA(DisplayName = "Arc Surface"),
	ThinSurface = 3 UMETA(DisplayName = "Thin Surface"),
};
