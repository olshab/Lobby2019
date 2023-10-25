#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ECurrencyType.h"
#include "StandDisplayable.h"
#include "CurrencyDisplayable.generated.h"

class UDBDSkeletalMeshComponentBudgeted;
class USkeletalMesh;

UCLASS()
class ACurrencyDisplayable : public AActor, public IStandDisplayable
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export)
	UDBDSkeletalMeshComponentBudgeted* SkeletalMeshComponent;

private:
	UPROPERTY(EditDefaultsOnly)
	TMap<ECurrencyType, USkeletalMesh*> _currencyMeshes;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void FinishSpawningCurrency(ECurrencyType currencyType);

protected:
	UFUNCTION(BlueprintNativeEvent)
	void BeginDestroySequence_Internal();

public:
	ACurrencyDisplayable();
};

FORCEINLINE uint32 GetTypeHash(const ACurrencyDisplayable) { return 0; }
