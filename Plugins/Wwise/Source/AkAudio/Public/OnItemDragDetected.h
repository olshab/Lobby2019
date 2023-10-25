#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnItemDragDetected.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemDragDetected, FGuid, ItemDraggedID, const FString&, ItemDraggedName);
