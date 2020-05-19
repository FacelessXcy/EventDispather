// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Receiver_R.h"
#include "Kismet/GameplayStatics.h"
#include "UECpp_Sender.h"
#include "Engine/Engine.h"



void AUECpp_Receiver_R::BeginPlay()
{
	Super::BeginPlay();

	AUECpp_Sender* PlayerPawn = Cast<AUECpp_Sender>(UGameplayStatics::GetPlayerPawn(this, 0));

	//�����¼�
	PlayerPawn->UECpp_Broadcast.AddUObject(this, &AUECpp_Receiver_R::OnReceived);
	//PlayerPawn->UECpp_Broadcast.AddUFunction();//ʹ�õĺ�����Ҫ��UFUNCTION�ĺ�

	
}

void AUECpp_Receiver_R::OnReceived(int Param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Red, FString::Printf(TEXT("%i"), Param));
}
