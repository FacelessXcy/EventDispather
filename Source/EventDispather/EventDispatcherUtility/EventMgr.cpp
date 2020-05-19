// Fill out your copyright notice in the Description page of Project Settings.


#include "EventMgr.h"
#include "EventInterface.h"
#include "Engine.h"


TMap<FString, TArray<UObject*>> UEventMgr::AllListeners;

void UEventMgr::AddEventListener(FString EventName, UObject* Listener)
{
	if (EventName==""||//�¼�������Ϊ��
		Listener==nullptr||//Listener����Ϊ��
		!Listener->IsValidLowLevel()||//Listener�ڵײ�δ������
		!Listener->GetClass()->ImplementsInterface (UEventInterface::StaticClass()))//Listener�Ƿ�ʵ����UEventInterface�Ľӿ�
	{
		return;
	}
	TArray<UObject*>* Arr = UEventMgr::AllListeners.Find(EventName);
	if (Arr==nullptr||Arr->Num()==0)
	{
		TArray<UObject*> NewArr = { Listener };
		UEventMgr::AllListeners.Add(EventName, NewArr);
	}
	else
	{
		Arr->Add(Listener);
	}
}

void UEventMgr::RemoveEventListener(FString EventName, UObject* Listener)
{
	TArray<UObject*>* Arr = UEventMgr::AllListeners.Find(EventName);
	if (Arr!=nullptr&&Arr->Num()!=0)
	{
		Arr->Remove(Listener);
	}
}

FString UEventMgr::DispatchEvent(FString EventName, UObject* Data)
{
	TArray<UObject*>* Arr = UEventMgr::AllListeners.Find(EventName);
	if (Arr == nullptr || Arr->Num() == 0)
	{
		return "'" + EventName + "' No Listener.";
	}
	FString ErrorInfo = "\n";

	for (int i = 0; i < Arr->Num(); i++)
	{
		UObject* Obj = (*Arr)[i];
		if (Obj == nullptr ||//Listener����Ϊ��
			!Obj->IsValidLowLevel() ||//Listener�ڵײ�δ������
			!Obj->GetClass()->ImplementsInterface(UEventInterface::StaticClass()))//Listener�Ƿ�ʵ����UEventInterface�Ľӿ�
		{
			//TArray��ɾ��ʱ�����Զ���ɾ��Ԫ�غ����Ԫ��ǰ�ƣ�����λ
			Arr->RemoveAt(i);
			i--;
		}
		else
		{
			UFunction* Fun = Obj->FindFunction("OnReceiveEvent");
			if (Fun==nullptr||!Fun->IsValidLowLevel())
			{
				ErrorInfo += "'" + Obj->GetName() + "' No 'OnReceiveEvent' Function.\n";
			}
			else
			{
				Obj->ProcessEvent(Fun, &Data);
			}
		}
	}
	return ErrorInfo;
}


UObject* UEventMgr::NewAsset(UClass* ClassType)
{
	UObject* Obj = NewObject<UObject>(GetTransientPackage(), ClassType);
	return Obj;
}
