// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "VehiclePawn.generated.h"

/**
 *
 */
UCLASS()
class ESCAPEKART_API AVehiclePawn : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	AVehiclePawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/*Throttle/Steering*/
	void ApplyThrottle(float Val);
	void ApplySteering(float Val);

	/*Look around*/
	void LookUp(float Val);
	void Turn(float Val);

	/*Handbrake*/
	void onHandbrakePressed();
	void onHandbrakeReleased();

	/*Update in air physics*/
	void UpdateInAirControl(float DeltaTime);

protected:
	/*Spring arm that will offset the camera*/
	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringArm;

	UPROPERTY(Category = Camera, EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;
};
