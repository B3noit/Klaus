// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "ServerManager.generated.h"

/**
 * 
 */
UCLASS()
class KLAUS_API UServerManager : public UObject
{
	GENERATED_BODY()

public: // Variables

	UWorld* CurrentWorld;

	
public: // Methods

	UServerManager();

	
};