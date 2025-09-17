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

    // Heart naturally rises over time (stress effect if player is idle)
    CurrentHeartRate += NaturalRisePerSecond * DeltaTime;

    // Keep the value within safe bounds
    CurrentHeartRate = FMath::Clamp(CurrentHeartRate, MinHeartRate, MaxHeartRate);
}

// Apply inhale effect (smaller calming effect)
void UHeartRateComponent::ApplyBreathIn()
{
    CurrentHeartRate = FMath::Clamp(CurrentHeartRate - BreathChange * 0.5f, MinHeartRate, MaxHeartRate);
}

// Apply exhale effect (stronger calming effect)
void UHeartRateComponent::ApplyBreathOut()
{
    CurrentHeartRate = FMath::Clamp(CurrentHeartRate - BreathChange, MinHeartRate, MaxHeartRate);
}
