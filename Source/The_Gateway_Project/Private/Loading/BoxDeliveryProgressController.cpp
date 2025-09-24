// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Loading/BoxDeliveryProgressController.h"

#include "GatewayConfiguration.h"

void ABoxDeliveryProgressController::OnTick(float DeltaTime)
{
	Super::OnTick(DeltaTime);
	
	int lightCount = PointLights.Num();
	for (int i = 0; i < lightCount; i++)
	{
		auto v = PointLights[i];
		auto pointLight = Cast<APointLight>(v);
			
		float transitionPhase = static_cast<float>(i)/static_cast<float>(lightCount) * LightDisableTransitionAlpha;
		
		if (TransitionProgress < 0.5f)
		{
			float subTransitionProgress = TransitionProgress*2;
			if (pointLight->IsEnabled() && subTransitionProgress > transitionPhase)
			{
				pointLight->ToggleEnabled();
			}
		}
		else
		{
			float undoTransitionPhase = 1-transitionPhase;

			float subTransitionProgress = TransitionProgress/2;
			if (!pointLight->IsEnabled() && subTransitionProgress > undoTransitionPhase)
			{
				pointLight->ToggleEnabled();
			}
		}
	}
	
	if (TransitionProgress >= 0.5f) { FinalizeSequence(); }
}

void ABoxDeliveryProgressController::OnPreTransition()
{
	TransitionDuration = 1;
	PointLights = GetPointLights();
	UE_LOG(GWLogDayChange, Display, TEXT("PointLights found: %d"), PointLights.Num())
}

TArray<AActor*> ABoxDeliveryProgressController::GetPointLights()
{
	TArray<AActor*> pointLights;
	UGameplayStatics::GetAllActorsOfClass(this, APointLight::StaticClass(), pointLights);

	return pointLights;
}

