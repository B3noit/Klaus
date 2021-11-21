// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "KlausGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class KLAUS_API UKlausGameInstance : public UGameInstance
{
	GENERATED_BODY()

	
public: // Properties
	UPROPERTY(BlueprintReadWrite)
	class UServerManager* ServerManager;

public: // Methods
	UKlausGameInstance();

	virtual void OnStart() override;

};
