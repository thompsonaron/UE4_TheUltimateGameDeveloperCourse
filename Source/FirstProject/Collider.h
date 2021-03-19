// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColliderMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Collider.generated.h"

UCLASS()
class FIRSTPROJECT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// basic Mesh, UPROPERTY() is added so that it is garbage collected
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
		class USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UColliderMovementComponent* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;


	// FORCEINLINE will make this method pasted everywhere where it is called on compile
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() { return MeshComponent; }
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh) { MeshComponent = Mesh; }

	FORCEINLINE USphereComponent* GetSphereComponent() { return SphereComponent; }
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere) { SphereComponent = Sphere; }	
	
	FORCEINLINE UCameraComponent* GetCameraComponent() { return CameraComponent; }
	FORCEINLINE void SetCameraComponent(UCameraComponent* Camera) { CameraComponent = Camera; }

	FORCEINLINE USpringArmComponent* GetSpringArmComponent() { return SpringArmComponent; }
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* SpringArm) { SpringArmComponent = SpringArm; }


private:
	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void CameraPitch(float AxisValue);
	void CameraYaw(float AxisValue);

	FVector2D CameraInput;
};
