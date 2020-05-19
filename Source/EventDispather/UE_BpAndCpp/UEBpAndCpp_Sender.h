// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UEBpAndCpp_Sender.generated.h"

UCLASS()
class EVENTDISPATHER_API AUEBpAndCpp_Sender : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUEBpAndCpp_Sender();

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUEBpAndCpp_Broadcast, int, Param);
	UPROPERTY(BlueprintAssignable)
	FUEBpAndCpp_Broadcast UEBpAndCpp_Broadcast;


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
