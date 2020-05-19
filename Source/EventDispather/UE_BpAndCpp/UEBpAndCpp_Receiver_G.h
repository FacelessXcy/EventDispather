// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE_BpAndCpp/UEBpAndCpp_Receiver_Parent.h"
#include "UEBpAndCpp_Receiver_G.generated.h"

/**
 * 
 */
UCLASS()
class EVENTDISPATHER_API AUEBpAndCpp_Receiver_G : public AUEBpAndCpp_Receiver_Parent
{
	GENERATED_BODY()
public:

protected:
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void OnReceived(int Param);
};
