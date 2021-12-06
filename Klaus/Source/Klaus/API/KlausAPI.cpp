// Fill out your copyright notice in the Description page of Project Settings.


#include "KlausAPI.h"

#include "HttpManager.h"
#include "JsonUtilities.h"
#include "Runtime/Online/HTTP/Public/Http.h"


TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UKlausAPI::MakeRequest(
	FString FunctionName,
	TSharedPtr<FJsonObject> Params
) {
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	FString Url = "127.0.0.1:30010/remote/object/call";
	Request->SetURL(Url);
	Request->SetVerb("PUT");

	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent; charset=utf-8"));
	Request->SetHeader(TEXT("content-type"), TEXT("application/json"));

	Request->SetContentAsString(MakeBodyJson(FunctionName, Params));

	return Request;
}

FString UKlausAPI::MakeBodyJson(FString FunctionName, TSharedPtr<FJsonObject> Params)
{
	TSharedPtr<FJsonObject> JsonObjectToSend = MakeShareable(new FJsonObject());
	JsonObjectToSend->SetStringField(TEXT("objectPath"), TEXT("/Engine/Transient.ServerManager_0"));
	JsonObjectToSend->SetStringField(TEXT("functionName"), FunctionName);
	JsonObjectToSend->SetObjectField(TEXT("parameters"), Params);

	FString OutputString;   
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObjectToSend.ToSharedRef(), JsonWriter);

	return OutputString;
}


TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UKlausAPI::MakeRequest(FString FunctionName)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
	FString Url = "192.168.13.23 :30010/remote/object/call";
	Request->SetURL(Url);
	Request->SetVerb("PUT");

	Request->SetHeader(TEXT("User-Agent"), TEXT("X-UnrealEngine-Agent; charset=utf-8"));
	Request->SetHeader(TEXT("content-type"), TEXT("application/json"));

	Request->SetContentAsString(MakeBodyJson(FunctionName));

	return Request;
}


FString UKlausAPI::MakeBodyJson(FString FunctionName)
{
	TSharedPtr<FJsonObject> JsonObjectToSend = MakeShareable(new FJsonObject());
	JsonObjectToSend->SetStringField(TEXT("objectPath"), TEXT("/Engine/Transient.ServerManager_0"));
	JsonObjectToSend->SetStringField(TEXT("functionName"), FunctionName);

	FString OutputString;   
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObjectToSend.ToSharedRef(), JsonWriter);

	return OutputString;
}
