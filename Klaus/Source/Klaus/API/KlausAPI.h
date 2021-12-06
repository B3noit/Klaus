// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "KlausAPI.generated.h"

UCLASS()
class KLAUS_API UKlausAPI :  public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public: // Variables
    
public: // Methods 
	static TSharedRef<class IHttpRequest, ESPMode::ThreadSafe> MakeRequest(
		FString FunctionName,
		TSharedPtr<class FJsonObject> Params
	);
    
	static FString MakeBodyJson(FString FunctionName, TSharedPtr<class FJsonObject> Params);

	static TSharedRef<class IHttpRequest, ESPMode::ThreadSafe> MakeRequest(
	FString FunctionName
);

	static FString MakeBodyJson(FString FunctionName);
};