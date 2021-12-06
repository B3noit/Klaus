// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KlausClickerUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class KLAUS_API UKlausClickerUserWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void CallKlaus();
	
};
