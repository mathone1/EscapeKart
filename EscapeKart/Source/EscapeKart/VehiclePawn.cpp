// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"

static const FName NAME_SteerInput("Steer");
static const FName NAME_ThrottleInput("Throttle");

AVehiclePawn::AVehiclePawn() {
	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());

	// Adjust the tire loading
	Vehicle4W->MinNormalizedTireLoad = 0.0f;
	//Vehicle4W->MinNormalizedTireLoadFiltered = 0.2f;
	//Vehicle4W->MaxNormalizedTireLoad = 2.0f;
	//Vehicle4W->MaxNormalizedTireLoadFiltered = 2.0f;
	Vehicle4W->MinNormalizedTireLoadFiltered = 2.0f;
	Vehicle4W->MaxNormalizedTireLoad = 3.0f;
	Vehicle4W->MaxNormalizedTireLoadFiltered = 3.0f;

	// Torque setup
	Vehicle4W->MaxEngineRPM = 8000000.0f;
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
	//Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 38.0f);
	//Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(40.0f, 80.0f);
	//Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(100.0f, 160.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 4000000.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.1f, 6000000.0f);
	Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.2f, 8000000.0f);

	// Adjust the steering 
	Vehicle4W->SteeringCurve.GetRichCurve()->Reset();
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(0.0f, 1.0f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(40.0f, 0.7f);
	Vehicle4W->SteeringCurve.GetRichCurve()->AddKey(120.0f, 0.6f);

	Vehicle4W->DifferentialSetup.DifferentialType = EVehicleDifferential4W::LimitedSlip_4W;
	Vehicle4W->DifferentialSetup.FrontRearSplit = 0;

	// Automatic gearbox
	Vehicle4W->TransmissionSetup.bUseGearAutoBox = true;
	Vehicle4W->TransmissionSetup.GearSwitchTime = 0;
	Vehicle4W->TransmissionSetup.GearAutoBoxLatency = 0;

	// Create a spring arm component for our chase camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 250.0f;
	SpringArm->bUsePawnControlRotation = true;

	// Create the chase camera component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->FieldOfView = 110.0f;

}

void AVehiclePawn::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	UpdateInAirControl(DeltaTime);
}

void AVehiclePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(NAME_ThrottleInput, this, &AVehiclePawn::ApplyThrottle);
	PlayerInputComponent->BindAxis(NAME_SteerInput, this, &AVehiclePawn::ApplySteering);
	PlayerInputComponent->BindAxis("LookUp", this, &AVehiclePawn::LookUp);
	PlayerInputComponent->BindAxis("Turn", this, &AVehiclePawn::Turn);

	PlayerInputComponent->BindAction("Handbrake", IE_Pressed, this, &AVehiclePawn::onHandbrakePressed);
	PlayerInputComponent->BindAction("Handbrake", IE_Released, this, &AVehiclePawn::onHandbrakeReleased);

	PlayerInputComponent->BindAction("Accelerate", IE_Pressed, this, &AVehiclePawn::onAcceleratePressed);
	PlayerInputComponent->BindAction("Accelerate", IE_Released, this, &AVehiclePawn::onAccelerateReleased);
}

void AVehiclePawn::ApplyThrottle(float Val) {
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}

void AVehiclePawn::ApplySteering(float Val) {
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void AVehiclePawn::LookUp(float Val) {
	if (Val != 0.f) {
		AddControllerPitchInput(-Val);
	}
}

void AVehiclePawn::Turn(float Val) {
	if (Val != 0.f) {
		AddControllerYawInput(Val);
	}
}

void AVehiclePawn::onHandbrakePressed() {
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AVehiclePawn::onHandbrakeReleased() {
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AVehiclePawn::onAcceleratePressed() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Accelerate")));
	if (UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement())) {

		Vehicle4W->MinNormalizedTireLoadFiltered = 4.0f;
		Vehicle4W->MaxNormalizedTireLoad = 5.0f;
		Vehicle4W->MaxNormalizedTireLoadFiltered = 5.0f;

		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 400.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(1.0f, 50000.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(2.0f, 400000.0f);

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Applied")));
	}
}

void AVehiclePawn::onAccelerateReleased() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Stop Accelerate")));
	if (UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement())) {

		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 38.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(40.0f, 80.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(100.0f, 160.0f);

		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->Reset();
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(0.0f, 8.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(10.0f, 18.0f);
		Vehicle4W->EngineSetup.TorqueCurve.GetRichCurve()->AddKey(20.0f, 22.0f);
	}
}

void AVehiclePawn::UpdateInAirControl(float DeltaTime) {
	if (UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement())) {
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);

		const FVector TraceStart = GetActorLocation() + FVector(0.f, 0.f, 50.f);
		const FVector TraceEnd = GetActorLocation() - FVector(0.f, 0.f, 200.f);

		FHitResult Hit;

		// Check if car is flipped on its side and check if the car is in the air
		const bool bInAir = !GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, ECC_Visibility, QueryParams);
		const bool bNotGrounded = FVector::DotProduct(GetActorUpVector(), FVector::UpVector) < 0.1f;

		// Only allow in air-movement if we are not on the ground, or if we are in the air
		if (bInAir || bNotGrounded) {
			const float ForwardInput = InputComponent->GetAxisValue(NAME_ThrottleInput);
			const float RightInput = InputComponent->GetAxisValue(NAME_SteerInput);

			// If car is grounded, allow player to roll the car over
			const float AirMovementForcePitch = 1.5f;
			const float AirMovementForceRoll = !bInAir && bNotGrounded ? 20.f : 1.5f;

			if (UPrimitiveComponent* vehicleMesh = Vehicle4W->UpdatedPrimitive) {
				const FVector MovementVector = FVector(RightInput * -AirMovementForceRoll, ForwardInput * AirMovementForcePitch, 0.f) * DeltaTime * 200.f;
				const FVector NewAngularMovement = GetActorRotation().RotateVector(MovementVector);

				vehicleMesh->SetPhysicsAngularVelocity(NewAngularMovement, true);
			}
		}
	}
}