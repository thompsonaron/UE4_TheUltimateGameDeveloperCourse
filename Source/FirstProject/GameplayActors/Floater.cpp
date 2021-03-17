// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));
	SetRootComponent(StaticMesh);

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin= FVector(0.0f, 0.0f, 0.0f);
	InitialDirection = FVector(0.0f, 0.0f, 0.0f);
	

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(200000.f, 0.0f, 0.0f);
	InitialTorque = FVector(200000.f, 0.0f, 0.0f);

	RunningTime = 0.0f;

	Amplitude = 1.f;
	Period = 0.f;
	PhaseShift = 0.f;
	VerticalShift = 0.f;

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float InitalX = FMath::FRandRange(-500.f, 500.f);
	float InitalY = FMath::FRandRange(-500.f, 500.f);
	float InitalZ = FMath::FRandRange(0.f, 500.f);

	InitialLocation.X = InitalX;
	InitialLocation.Y = InitalY;
	InitialLocation.Z = InitalZ;


	PlacedLocation = GetActorLocation();

	BaseZLocation = PlacedLocation.Z;

	// setting actor location 
	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation);
	}


	//FHitResult HitResult;
	//FVector LocalOffset = FVector(200.f, 0.0f, 0.0f);

	//AddActorLocalOffset(LocalOffset, true, &HitResult);
	//AddActorWorldOffset(LocalOffset, true, &HitResult);

	
	
	/*StaticMesh->AddForce(InitialForce);
	StaticMesh->AddTorqueInRadians(InitialTorque);*/

}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		//FHitResult HitResult;

		//AddActorLocalOffset(InitialDirection, true, &HitResult);

		//FVector HitLocation = HitResult.Location;

		//UE_LOG(LogTemp, Warning, TEXT("Hit location: X = %f, Y = %f, Z = %f"), HitLocation.X, HitLocation.Y, HitLocation.Z);

		FVector NewLocation = GetActorLocation();


		NewLocation.Z = BaseZLocation + Amplitude * FMath::Sin(Period * RunningTime - PhaseShift) + VerticalShift; // Basic Period = 2 * PI - we adjust it through B (Period)

		SetActorLocation(NewLocation);

		RunningTime += DeltaTime;
	}

	/*FRotator Rotation = FRotator(0.0f, 0.0f, 1.0f);

	AddActorWorldRotation(Rotation);*/

}

