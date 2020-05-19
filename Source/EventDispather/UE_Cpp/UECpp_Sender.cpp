// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Sender.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TimerManager.h"

// Sets default values
AUECpp_Sender::AUECpp_Sender()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	this->RootComponent = this->Sphere;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (StaticMeshAsset.Succeeded()&&MaterialAsset.Succeeded())
	{
		this->Sphere->SetStaticMesh(StaticMeshAsset.Object);
		this->Sphere->SetMaterial(0, MaterialAsset.Object);
	}


}

// Called when the game starts or when spawned
void AUECpp_Sender::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle TimerHandle;
	auto Lambda = [](FUECpp_Broadcast* ucb)
	{
		ucb->Broadcast(FMath::RandRange(0, 100));
	};
	GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda, &this->UECpp_Broadcast), 3.0f, true);
	

}

// Called every frame
void AUECpp_Sender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUECpp_Sender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

