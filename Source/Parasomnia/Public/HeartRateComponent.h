// HeartRateComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeartRateComponent.generated.h"

/**
 * Component that simulates a heart rate system.
 * - Heart rate rises naturally over time (stress if not breathing).
 * - Player breathing lowers the heart rate.
 * - Used for win/loss conditions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PARASOMNIA_API UHeartRateComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Constructor
    UHeartRateComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /** Current simulated heart rate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float CurrentHeartRate;

    /** Initial starting heart rate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float StartingHeartRate = 80.f;

    /** Max heart rate before the player loses */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float MaxHeartRate = 180.f;

    /** Min heart rate before the player wins */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float MinHeartRate = 50.f;

    /** How fast the heart rises naturally per second */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float NaturalRisePerSecond = 3.f;

    /** How much each breath changes the heart rate */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeartRate")
    float BreathChange = 5.f;

    /** Apply inhale effect (small calming effect) */
    UFUNCTION(BlueprintCallable, Category = "HeartRate")
    void ApplyBreathIn();

    /** Apply exhale effect (stronger calming effect) */
    UFUNCTION(BlueprintCallable, Category = "HeartRate")
    void ApplyBreathOut();
};
