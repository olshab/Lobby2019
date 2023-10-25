#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Services/BTService_RunEQS.h"
#include "BTService_AroundEQS.generated.h"

UCLASS()
class DBDBOTS_API UBTService_AroundEQS : public UBTService_RunEQS
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly)
	FBlackboardKeySelector BBAroundObj;

	UPROPERTY(EditInstanceOnly)
	FBlackboardKeySelector BBAroundLocation;

	UPROPERTY(EditInstanceOnly)
	float ValidLocationRefreshInterval;

	UPROPERTY(EditInstanceOnly)
	float InvalidLocationRefreshInterval;

	UPROPERTY(EditInstanceOnly)
	float InvalidateLocationUnderTargetDistance;

	UPROPERTY(EditInstanceOnly)
	bool KeepResultWhileValid;

	UPROPERTY(EditInstanceOnly)
	FName NavDataAgentName;

	UPROPERTY(EditInstanceOnly)
	FVector NavMeshProjectionBoxExtent;

public:
	UBTService_AroundEQS();
};

FORCEINLINE uint32 GetTypeHash(const UBTService_AroundEQS) { return 0; }
