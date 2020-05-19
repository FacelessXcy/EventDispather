// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UECpp_Sender.generated.h"

UCLASS()
class EVENTDISPATHER_API AUECpp_Sender : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUECpp_Sender();

	DECLARE_MULTICAST_DELEGATE_OneParam(FUECpp_Broadcast, int);
	FUECpp_Broadcast UECpp_Broadcast;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* Sphere;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
