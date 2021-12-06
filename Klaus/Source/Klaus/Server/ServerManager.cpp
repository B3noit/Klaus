// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerManager.h"

#include "Kismet/GameplayStatics.h"

UServerManager::UServerManager()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf(TEXT("ServerManager Path : %s"), *this->GetPathName()));
}

void UServerManager::CallKlaus()
{
	this->OnCallKlaus.Broadcast(FMath::RandRange(0,2));
}
