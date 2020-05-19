// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "My_BpAndCpp/MyBpAndCpp_Receiver_Parent.h"
#include "EventDispatcherUtility/EventInterface.h"
#include "MyBpAndCpp_Receiver_G.generated.h"

/**
 * 
 */
//一定要继承IEventInterface
UCLASS()
class EVENTDISPATHER_API AMyBpAndCpp_Receiver_G : public AMyBpAndCpp_Receiver_Parent,public IEventInterface
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void BeginDestroy() override;

	//一定要实现的是_Implementation后缀版本的函数
	virtual void OnReceiveEvent_Implementation(UObject* Data) override;


};
