// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBpAndCpp_Sender.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "EventDispatcherUtility/EventMgr.h"
#include "TimerManager.h"
#include "MyData.h"

// Sets default values
AMyBpAndCpp_Sender::AMyBpAndCpp_Sender()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	this->RootComponent = this->Sphere;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded())
	{
		this->Sphere->SetStaticMesh(StaticMeshAsset.Object);
		this->Sphere->SetMaterial(0, MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void AMyBpAndCpp_Sender::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	auto Lambda = []() 
	{
		UMyData* Data = Cast<UMyData>(UEventMgr::NewAsset(UMyData::StaticClass()));
		Data->Param = FMath::RandRange(0, 100);
		UEventMgr::DispatchEvent("MyBpAndCpp_DispatchEvent", Data);
	};
	GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda(Lambda), 3.0f, true);
	
}

// Called every frame
void AMyBpAndCpp_Sender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyBpAndCpp_Sender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

