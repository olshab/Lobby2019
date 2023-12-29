#pragma once

#include "CoreMinimal.h"
#include "PlayerCardViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "CorePlayerCardWidget.generated.h"

class UDBDImage;
class UOverlay;

UCLASS(EditInlineNew)
class DBDUIVIEWSCORE_API UCorePlayerCardWidget : public UCoreBaseUserWidget, public IPlayerCardViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UDBDImage* Icon;

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UOverlay* AnimationContainer;

public:
	UCorePlayerCardWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCorePlayerCardWidget) { return 0; }
