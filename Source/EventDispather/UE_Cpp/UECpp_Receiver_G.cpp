// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Receiver_G.h"
#include "Kismet/GameplayStatics.h"
#include "UECpp_Sender.h"
#include "Engine/Engine.h"

void AUECpp_Receiver_G::BeginPlay()
{
	Super::BeginPlay();

	AUECpp_Sender* PlayerPawn = Cast<AUECpp_Sender>(UGameplayStatics::GetPlayerPawn(this, 0));

	//订阅事件
	FDelegateHandle DelegateHandle = PlayerPawn->UECpp_Broadcast.AddUObject(this, &AUECpp_Receiver_G::OnReceived);
	//PlayerPawn->UECpp_Broadcast.AddUFunction();//使用的函数需要加UFUNCTION的宏

	//取消订阅事件
	FTimerHandle TimerHandle;
	auto Lambda = [PlayerPawn, DelegateHandle]()
	{
		PlayerPawn->UECpp_Broadcast.Remove(DelegateHandle);

		//清空本类注册的所有函数
		//PlayerPawn->UECpp_Broadcast.RemoveAll(this);
		//清空所有类注册的所有函数
		//PlayerPawn->UECpp_Broadcast.Clear();
	};
	GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda), 5.0f, false);
}

void AUECpp_Receiver_G::OnReceived(int Param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Param));
}