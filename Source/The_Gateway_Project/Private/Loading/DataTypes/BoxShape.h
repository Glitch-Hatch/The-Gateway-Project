#pragma once

UENUM(BlueprintType)
enum class EBoxShape: uint8
{
	ArcDeep = 0 UMETA(DisplayName = "Arc Deep", ToolTip = "Inside arc of module."),
	ThinDeep = 1 UMETA(DisplayName = "Thin Deep", ToolTip = "Inside boxes of module."),
	
	ArcSurface = 2 UMETA(DisplayName = "Arc Surface", ToolTip = "Outside arc of module."),
	ThinSurface = 3 UMETA(DisplayName = "Thin Surface", ToolTip = "Outside boxes of module."),
};
