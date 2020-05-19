// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Receiver_G.h"
#include "Kismet/GameplayStatics.h"
#include "UECpp_Sender.h"
#include "Engine/Engine.h"

void AUECpp_Receiver_G::BeginPlay()
{
	Super::BeginPlay();

	AUECpp_Sender* PlayerPawn = Cast<AUECpp_Sender>(UGameplayStatics::GetPlayerPawn(this, 0));

	//�����¼�
	FDelegateHandle DelegateHandle = PlayerPawn->UECpp_Broadcast.AddUObject(this, &AUECpp_Receiver_G::OnReceived);
	//PlayerPawn->UECpp_Broadcast.AddUFunction();//ʹ�õĺ�����Ҫ��UFUNCTION�ĺ�

	//ȡ�������¼�
	FTimerHandle TimerHandle;
	auto Lambda = [PlayerPawn, DelegateHandle]()
	{
		PlayerPawn->UECpp_Broadcast.Remove(DelegateHandle);

		//��ձ���ע������к���
		//PlayerPawn->UECpp_Broadcast.RemoveAll(this);
		//���������ע������к���
		//PlayerPawn->UECpp_Broadcast.Clear();
	};
	GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda), 5.0f, false);
}

void AUECpp_Receiver_G::OnReceived(int Param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Param));
}