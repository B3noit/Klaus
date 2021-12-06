// Fill out your copyright notice in the Description page of Project Settings.


#include "KlausClickerUserWidget.h"

#include "Klaus/API/KlausAPI.h"

void UKlausClickerUserWidget::CallKlaus()
{
	UKlausAPI::MakeRequest("CallKlaus");
}
