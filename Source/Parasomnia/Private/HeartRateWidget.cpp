// HeartRateWidget.cpp

#include "HeartRateWidget.h"
#include "Components/TextBlock.h"

void UHeartRateWidget::UpdateHeartRate(float NewHeartRate)
{
    if (HeartRateText)
    {
        // Format the heart rate as BPM (beats per minute)
        FString RateString = FString::Printf(TEXT("Heart Rate: %.0f BPM"), NewHeartRate);
        HeartRateText->SetText(FText::FromString(RateString));
    }
}
