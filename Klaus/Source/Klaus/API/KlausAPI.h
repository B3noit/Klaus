// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "KlausAPI.generated.h"

/**
 * 
 */
UCLASS()
class KLAUS_API UKlausAPI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public: // Variables 

public: // Methods 
    static TSharedRef<class IHttpRequest> MakeRequest(TSharedPtr<class FJsonObject> Params);
};
