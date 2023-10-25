#pragma once

#include "CoreMinimal.h"
#include "DataTableDropdown.generated.h"

USTRUCT(BlueprintType)
struct FDataTableDropdown
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	FName RowValue;

	UPROPERTY(EditAnywhere, Transient)
	FString DataTableName;

	UPROPERTY(EditAnywhere, Transient)
	FName ColumnName;

public:
	DEADBYDAYLIGHT_API FDataTableDropdown();
};

FORCEINLINE uint32 GetTypeHash(const FDataTableDropdown) { return 0; }
