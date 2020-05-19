// Fill out your copyright notice in the Description page of Project Settings.


#include "UECpp_Receiver_Parent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AUECpp_Receiver_Parent::AUECpp_Receiver_Parent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
void AUECpp_Receiver_Parent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUECpp_Receiver_Parent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

