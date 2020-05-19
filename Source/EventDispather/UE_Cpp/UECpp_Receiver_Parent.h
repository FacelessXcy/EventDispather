// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UECpp_Receiver_Parent.generated.h"

UCLASS()
class EVENTDISPATHER_API AUECpp_Receiver_Parent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUECpp_Receiver_Parent();

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Sphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
