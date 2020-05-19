// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_BpAndCpp/MyBpAndCpp_Receiver_Parent.h"
#include "EventDispatcherUtility/EventInterface.h"
#include "MyBpAndCpp_Receiver_G.generated.h"

/**
 * 
 */
//һ��Ҫ�̳�IEventInterface
UCLASS()
class EVENTDISPATHER_API AMyBpAndCpp_Receiver_G : public AMyBpAndCpp_Receiver_Parent,public IEventInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void BeginDestroy() override;

	//һ��Ҫʵ�ֵ���_Implementation��׺�汾�ĺ���
	virtual void OnReceiveEvent_Implementation(UObject* Data) override;


};
