// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ServerManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCallKlaus, int, NumberIDScreamer);

UCLASS()
class KLAUS_API UServerManager : public UObject
{
	GENERATED_BODY()

public: // Variables

	UWorld* CurrentWorld;

	
public: // Methods

	UServerManager();

	UFUNCTION(BlueprintCallable)
	void CallKlaus();

	UPROPERTY(BlueprintAssignable)
	FOnCallKlaus OnCallKlaus;
};