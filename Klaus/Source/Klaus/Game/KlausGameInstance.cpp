// Fill out your copyright notice in the Description page of Project Settings.

#include "KlausGameInstance.h"
#include "Klaus/Server/ServerManager.h"

UKlausGameInstance::UKlausGameInstance(): Super() {
	if (!HasAnyFlags(RF_ClassDefaultObject | RF_ArchetypeObject)) {
		this->ServerManager = NewObject<UServerManager>();
	}
}

void UKlausGameInstance::OnStart() {
	if(GetWorld()) {
		this->ServerManager->CurrentWorld = GetWorld();
	} else {
		UE_LOG(LogTemp, Error, TEXT("There is no world on start of the game instance"))
	}
}