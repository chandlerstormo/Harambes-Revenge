// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "HarambesRevenge.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "HarambesRevengeCharacter.h"
#include "BananaActor.h"

//////////////////////////////////////////////////////////////////////////
// AHarambesRevengeCharacter

AHarambesRevengeCharacter::AHarambesRevengeCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	//FP_Gun->SetOnlyOwnerSee(true);			// only the owning player will see this mesh
	//FP_Gun->bCastDynamicShadow = false;
	//FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);

	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//void AHarambesRevengeCharacter::BeginPlay()
//{
	//score = 0;
	//UpdateScore(score);
	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	//FP_Gun->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

//}

//////////////////////////////////////////////////////////////////////////
// Input

void AHarambesRevengeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AHarambesRevengeCharacter::StartSprinting);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AHarambesRevengeCharacter::StopSprinting);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHarambesRevengeCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHarambesRevengeCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AHarambesRevengeCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AHarambesRevengeCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AHarambesRevengeCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AHarambesRevengeCharacter::TouchStopped);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AHarambesRevengeCharacter::OnFire);
	
	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AHarambesRevengeCharacter::OnResetVR);
}


void AHarambesRevengeCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AHarambesRevengeCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	// jump, but only on the first touch
	if (FingerIndex == ETouchIndex::Touch1)
	{
		Jump();
	}
}

void AHarambesRevengeCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		StopJumping();
	}
}

void AHarambesRevengeCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHarambesRevengeCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AHarambesRevengeCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		
			AddMovementInput(Direction, Value);
		
		// play walking animation
			//PlayAnimMontage(WalkAnim);
			
	}
}

void AHarambesRevengeCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
void AHarambesRevengeCharacter::StartSprinting() {
	sprinting = true;
}
void AHarambesRevengeCharacter::StopSprinting() {
	sprinting = false;
}
void AHarambesRevengeCharacter::OnFire()
{
	// try and fire a projectile
	if (ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if (World != NULL&&bananas>0)
		{
			const FRotator SpawnRotation = GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			//const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
			FVector SpawnLocation;
			if (FP_MuzzleLocation != nullptr) {
				SpawnLocation = FP_MuzzleLocation->GetComponentLocation();
			}
			else {
				SpawnLocation = GetActorLocation();
			}
			SpawnLocation += SpawnRotation.RotateVector(GunOffset);

			// spawn the projectile at the muzzle
			World->SpawnActor<ABananaActor>(ProjectileClass, SpawnLocation, SpawnRotation);
			bananas--;
			UpdateBananas(bananas);
			// play throwing animation
			PlayAnimMontage(ThrowAnim, ThrowAnimSpeed);
		}
	}


	

	// try and play the sound if specified
	//if (FireSound != NULL)
	//{
	//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	//}

	//// try and play a firing animation if specified
	//if (FireAnimation != NULL)
	//{
	//	// Get the animation object for the arms mesh
	//	UAnimInstance* AnimInstance = Mesh1P->GetAnimInstance();
	//	if (AnimInstance != NULL)
	//	{
	//		AnimInstance->Montage_Play(FireAnimation, 1.f);
	//	}
	//}
}

float AHarambesRevengeCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (DamageCauser != nullptr) {
		if (!DamageCauser->IsA<ABananaActor>()) {
			if (ActualDamage > 0.0f) {
				Health -= ActualDamage;

				UpdateHealth((int32)Health);
				if (Health <= 0.0f) {
					bCanBeDamaged = false;
					// Character is dead
					StopAnimMontage();
					float timeTillDestroy = PlayAnimMontage(DieAnim);
					FTimerHandle deathHandle;
					GetWorldTimerManager().SetTimer(deathHandle, this, &AHarambesRevengeCharacter::Die, timeTillDestroy - 0.25f);
					APlayerController* PC = Cast<APlayerController>(GetController());
					if (PC)
					{
						PC->SetCinematicMode(true, true, true);
					}
				}
			}
		}
	}
	return ActualDamage;
}
void AHarambesRevengeCharacter::onKill() {
	score += 10;
	UpdateScore(score);
}

void AHarambesRevengeCharacter::Die() {
	GetMesh()->Deactivate();
	FTimerHandle restart;
	GetWorldTimerManager().SetTimer(restart, this, &AHarambesRevengeCharacter::restartLevel, 5);
	Death();
}

void AHarambesRevengeCharacter::restartLevel() {
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void AHarambesRevengeCharacter::GainBanana() {
	bananas++;
	UpdateBananas(bananas);
}