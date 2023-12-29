#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RemoteContentCacheEntry.generated.h"

USTRUCT()
struct FRemoteContentCacheEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Schema;

	UPROPERTY()
	FString Uri;

	UPROPERTY()
	FString ContentVersion;

	UPROPERTY()
	FSoftObjectPath PackagedObjectPath;

private:
	UPROPERTY()
	bool _isPackaged;

public:
	REMOTECONTENTCACHE_API FRemoteContentCacheEntry();
};

FORCEINLINE uint32 GetTypeHash(const FRemoteContentCacheEntry) { return 0; }
