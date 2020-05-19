// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBpAndCpp_Receiver_G.h"
#include "Engine/Engine.h"
#include "MyData.h"
#include "EventDispatcherUtility/EventMgr.h"
#include "TimerManager.h"

void AMyBpAndCpp_Receiver_G::BeginPlay()
{
	Super::BeginPlay();
	UEventMgr::AddEventListener("MyBpAndCpp_DispatchEvent", this);

	FTimerHandle TimerHandle;
	auto Lambda = [this]()
	{
		UEventMgr::RemoveEventListener("MyBpAndCpp_DispatchEvent", this);
	};
	//GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda), 5.0f, false);

}


void AMyBpAndCpp_Receiver_G::BeginDestroy()
{
	//先取消订阅，在执行父类Destroy
	UEventMgr::RemoveEventListener("MyBpAndCpp_DispatchEvent", this);
	
	Super::BeginDestroy();
}



void AMyBpAndCpp_Receiver_G::OnReceiveEvent_Implementation(UObject* Data)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Cast<UMyData>(Data)->Param));
}
