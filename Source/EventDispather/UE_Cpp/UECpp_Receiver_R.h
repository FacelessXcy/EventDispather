// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE_Cpp/UECpp_Receiver_Parent.h"
#include "UECpp_Receiver_R.generated.h"

/**
 * 
 */
UCLASS()
class EVENTDISPATHER_API AUECpp_Receiver_R : public AUECpp_Receiver_Parent
{
	GENERATED_BODY()
	
public:

protected:
	virtual void BeginPlay() override;

public:
	void OnReceived(int Param);
};
