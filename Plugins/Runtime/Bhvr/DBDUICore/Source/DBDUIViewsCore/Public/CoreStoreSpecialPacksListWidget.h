#pragma once

#include "CoreMinimal.h"
#include "StoreSpecialPacksListViewInterface.h"
#include "CoreBaseUserWidget.h"
#include "Templates/SubclassOf.h"
#include "CoreStoreSpecialPacksListWidget.generated.h"

class UVerticalBox;
class UCorePreConstructableList;
class UCoreStoreSpecialPacksPackItemWidget;

UCLASS(EditInlineNew)
class UCoreStoreSpecialPacksListWidget : public UCoreBaseUserWidget, public IStoreSpecialPacksListViewInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	int32 _preConstructedItemsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, NoClear)
	TSubclassOf<UCoreStoreSpecialPacksPackItemWidget> _itemWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UVerticalBox* Content;

private:
	UPROPERTY(Transient)
	UCorePreConstructableList* _itemList;

private:
	UFUNCTION()
	void OnItemBuyActionClicked(const FString& packId);

public:
	UCoreStoreSpecialPacksListWidget();
};

FORCEINLINE uint32 GetTypeHash(const UCoreStoreSpecialPacksListWidget) { return 0; }
