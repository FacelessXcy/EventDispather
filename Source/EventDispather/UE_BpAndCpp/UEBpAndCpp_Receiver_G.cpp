// Fill out your copyright notice in the Description page of Project Settings.


#include "UEBpAndCpp_Receiver_G.h"
#include "UEBpAndCpp_Sender.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "TimerManager.h"

void AUEBpAndCpp_Receiver_G::BeginPlay()
{
	Super::BeginPlay();
	
	AUEBpAndCpp_Sender* PlayerPawn = Cast<AUEBpAndCpp_Sender>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerPawn->UEBpAndCpp_Broadcast.AddDynamic(this, &AUEBpAndCpp_Receiver_G::OnReceived);

	FTimerHandle TimerHandle;
	auto Lambda = [PlayerPawn,this]()
	{
		PlayerPawn->UEBpAndCpp_Broadcast.RemoveDynamic(this, &AUEBpAndCpp_Receiver_G::OnReceived);
	};
	GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda), 4.0f, false);
	
}

void AUEBpAndCpp_Receiver_G::OnReceived(int Param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Green, FString::Printf(TEXT("%i"), Param));
}
