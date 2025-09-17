#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HeartRateComponent.h"
#include "HeartRateWidget.h"
#include "PlayerPawn.generated.h"

UCLASS()
class PARASOMNIA_API APlayerPawn : public APawn
{
    GENERATED_BODY()

public:
    APlayerPawn();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UHeartRateComponent* HeartRateComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UHeartRateWidget> HeartRateWidgetClass;

    UHeartRateWidget* HeartRateWidgetInstance;

    void OnBreathIn();
    void OnBreathOut();
    void CheckHeartRateState();
};
