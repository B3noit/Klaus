// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "KlausAPI.generated.h"

typedef void RequestRetFun(TSharedPtr<IHttpRequest, ESPMode::Fast>, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe>,
    bool);

UCLASS()
class UKLAUS_API UHermesAPI : public UBlueprintFunctionLibrary {
    GENERATED_BODY()

public: // Variables 

public: // Methods

    template <typename UserClass, typename... VarTypes>
    static void SendRequest(
        FString Verb,
        FString Path,
        TSharedPtr<class FJsonObject> Params,
        UserClass* InUserObject,
        typename TMemFunPtrType<false, UserClass, RequestRetFun>::Type InFunc,
        VarTypes ...
    );

    static void SendRequest(
        FString Verb,
        FString Path,
        TSharedPtr<class FJsonObject> Params
    );


    static TSharedRef<IHttpRequest> SetUpRequest(FString Path, FString Verb, TSharedPtr<FJsonObject> Params);

protected: // Methods
};
