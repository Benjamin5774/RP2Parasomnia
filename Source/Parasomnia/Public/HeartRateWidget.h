// HeartRateWidget.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeartRateWidget.generated.h"

/**
 * Widget that displays the player's heart rate.
 * Must be paired with a UMG Widget Blueprint (WBP_HeartRate).
 */
UCLASS()
class PARASOMNIA_API UHeartRateWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    /** Reference to the text block in the UMG widget (must be named "HeartRateText") */
    UPROPERTY(meta = (BindWidget))
    class UTextBlock* HeartRateText;

    /** Called from C++ to update the displayed heart rate */
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateHeartRate(float NewHeartRate);
};
