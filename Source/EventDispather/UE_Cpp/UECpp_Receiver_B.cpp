// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Receiver_B.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "UECpp_Sender.h"

void AUECpp_Receiver_B::BeginPlay()
{
	Super::BeginPlay();

	AUECpp_Sender* PlayerPawn = Cast<AUECpp_Sender>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerPawn->UECpp_Broadcast.AddUObject(this, &AUECpp_Receiver_B::OnReceived);

}

void AUECpp_Receiver_B::OnReceived(int Param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, FColor::Blue, FString::Printf(TEXT("%i"), Param));
}
