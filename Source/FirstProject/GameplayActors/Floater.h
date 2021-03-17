// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Floater.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ActorMeshComponents")
	UStaticMeshComponent* StaticMesh;

	// location used by set SetActorLocation() when BeginPlay() is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector InitialLocation;

	// location of the Actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Floater Variables")
	FVector PlacedLocation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater Variables")
	FVector WorldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	bool bShouldFloat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Floater Variables")
	bool bInitializeFloaterLocations;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Floater Variables")
	FVector InitialForce;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Floater Variables")
	FVector InitialTorque;

private:
	float RunningTime;

	float BaseZLocation;

public:
	// A Amplitude - how much we oscillate up and down
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	float Amplitude;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	// B Period = 2 * PI /(absolute valule of B) - makar mislim da je to 1/B * time
	float Period;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	// C Phase shift - C / B
	float PhaseShift;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables")
	// D Vertical shift
	float VerticalShift;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
