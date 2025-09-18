// HeartRateComponent.cpp

#include "HeartRateComponent.h"   // Always include your own header first

// Constructor
UHeartRateComponent::UHeartRateComponent()
{
    // Enable ticking for this component
    PrimaryComponentTick.bCanEverTick = true;

    // Initialize current heart rate to the starting value
    CurrentHeartRate = StartingHeartRate;
}

// Called when the game starts
void UHeartRateComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void UHeartRateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (bIsBreathingIn)
    {
        CurrentHeartRate -= (BreathChange * 0.5) * DeltaTime;
    }
    else if (bIsBreathingOut)
    {
        CurrentHeartRate -= BreathChange * DeltaTime;

        ExhaleTimer += DeltaTime;
        if (ExhaleTimer >= MaxExhaleDuration)
        {
            StopBreathing();
        }
    }
    else
    {
        CurrentHeartRate += NaturalRisePerSecond * DeltaTime;
    }
    CurrentHeartRate = FMath::Clamp(CurrentHeartRate, MinHeartRate, MaxHeartRate);
}


// Apply inhale effect (smaller calming effect)
void UHeartRateComponent::ApplyBreathIn()
{
    bIsBreathingIn = true;
    bIsBreathingOut = false;
}

// Apply exhale effect (stronger calming effect)
void UHeartRateComponent::ApplyBreathOut()
{
    bIsBreathingIn = false;
    bIsBreathingOut = true;
    ExhaleTimer = 0.0f;
}

void UHeartRateComponent::StopBreathing()
{
    bIsBreathingIn = false;
    bIsBreathingOut = false;
}
