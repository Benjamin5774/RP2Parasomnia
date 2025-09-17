#include "PlayerPawn.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"

APlayerPawn::APlayerPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Root + Camera
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(RootComponent);

    // Heart system
    HeartRateComponent = CreateDefaultSubobject<UHeartRateComponent>(TEXT("HeartRateComponent"));

    // Auto-possess
    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerPawn::BeginPlay()
{
    Super::BeginPlay();

    if (HeartRateWidgetClass)
    {
        HeartRateWidgetInstance = CreateWidget<UHeartRateWidget>(GetWorld(), HeartRateWidgetClass);
        if (HeartRateWidgetInstance)
        {
            HeartRateWidgetInstance->AddToViewport();
        }
    }
}

void APlayerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (HeartRateWidgetInstance && HeartRateComponent)
    {
        HeartRateWidgetInstance->UpdateHeartRate(HeartRateComponent->CurrentHeartRate);
    }

    CheckHeartRateState();
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("BreathIn", IE_Pressed, this, &APlayerPawn::OnBreathIn);
    PlayerInputComponent->BindAction("BreathOut", IE_Pressed, this, &APlayerPawn::OnBreathOut);
}

void APlayerPawn::OnBreathIn()
{
    if (HeartRateComponent)
        HeartRateComponent->ApplyBreathIn();
}

void APlayerPawn::OnBreathOut()
{
    if (HeartRateComponent)
        HeartRateComponent->ApplyBreathOut();
}

void APlayerPawn::CheckHeartRateState()
{
    if (!HeartRateComponent) return;

    if (HeartRateComponent->CurrentHeartRate >= HeartRateComponent->MaxHeartRate)
    {
        UE_LOG(LogTemp, Warning, TEXT("LOSE: Heart rate too high!"));
    }
    else if (HeartRateComponent->CurrentHeartRate <= HeartRateComponent->MinHeartRate)
    {
        UE_LOG(LogTemp, Warning, TEXT("WIN: Heart rate calmed down!"));
    }
}
