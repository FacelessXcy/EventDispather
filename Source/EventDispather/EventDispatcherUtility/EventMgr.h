// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EventMgr.generated.h"

/**
 * 
 */
UCLASS()
class EVENTDISPATHER_API UEventMgr : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
private:
	static TMap<FString, TArray<UObject*>> AllListeners;

public:
	UFUNCTION(BlueprintCallable, Category = "Event Dispatcher Utility")
	static void AddEventListener(FString EventName, UObject* Listener);

	UFUNCTION(BlueprintCallable, Category = "Event Dispatcher Utility")
	static void RemoveEventListener(FString EventName, UObject* Listener);

	//返回值为错误信息
	UFUNCTION(BlueprintCallable, Category = "Event Dispatcher Utility")
	static FString DispatchEvent(FString EventName, UObject* Data);

	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Event Dispatcher Utility")
	static UObject* NewAsset(UClass* ClassType);
};
