#pragma once

#include "CoreMinimal.h"
#include "FK26AttachedCrowRemovalReason.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "DBDTunableRowHandle.h"
#include "TunableStat.h"
#include "K26AttachmentStatus.h"
#include "GameEventData.h"
#include "ECamperDamageState.h"
#include "K26AttachedCrow.generated.h"

class ASlasherPlayer;
class USceneComponent;
class UK26PowerOutlineUpdateStrategy;
class AK26AttachedCrow;
class UStaticMeshComponent;
class ACamperPlayer;
class UK26PowerStatusHandlerComponent;
class UDBDOutlineComponent;

UCLASS()
class AK26AttachedCrow : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	FTunableStat _lingerTime;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _infectionDelay;

	UPROPERTY(EditDefaultsOnly)
	FDBDTunableRowHandle _infectRadius;

	UPROPERTY(EditDefaultsOnly, Export)
	UK26PowerOutlineUpdateStrategy* _outlineUpdateStrategy;

	UPROPERTY(EditDefaultsOnly, Export)
	UDBDOutlineComponent* _outlineComponent;

	UPROPERTY(EditDefaultsOnly, Export)
	UStaticMeshComponent* _visualStaticMeshComponent;

	UPROPERTY(Export)
	USceneComponent* _rootComponent;

	UPROPERTY(Transient, Export)
	UK26PowerStatusHandlerComponent* _statusHandler;

	UPROPERTY(Transient)
	bool _authority_isInfecting;

	UPROPERTY(ReplicatedUsing=OnRep_AttachmentStatus)
	FK26AttachmentStatus _attachmentStatus;

private:
	UFUNCTION()
	void OnRep_AttachmentStatus();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnStopDetaching();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_OnStartDetaching();

	UFUNCTION()
	void HideOutline();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStopDetaching();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnStartDetaching();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnCrowAttached();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAuraShown();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAuraHidden();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void Cosmetic_OnAttachedCrowRemoved(FK26AttachedCrowRemovalReason removalReason);

private:
	UFUNCTION()
	void Authority_OnSurvivorWasUnhooked(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnSurvivorStatusIndicatorSet(const ACamperPlayer* survivor, AK26AttachedCrow* attachedCrow);

	UFUNCTION()
	void Authority_OnSurvivorExitLocker(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnSurvivorDroppedEnd();

	UFUNCTION()
	void Authority_OnSurvivorAdded(ACamperPlayer* survivor);

	UFUNCTION()
	void Authority_OnPlayerLeftGame(FGameplayTag gameEventType, const FGameEventData& gameEventData);

	UFUNCTION()
	void Authority_OnOtherSurvivorPerkFlagsChanged(FGameplayTag gameplayTag, bool isAdded);

	UFUNCTION()
	void Authority_OnOtherSurvivorGuidedActionChanged();

	UFUNCTION()
	void Authority_OnOtherSurvivorDamageStateChanged(ECamperDamageState before, ECamperDamageState after);

	UFUNCTION()
	void Authority_OnOtherAttachedCrowRemoved();

	UFUNCTION()
	void Authority_OnKillerSet(ASlasherPlayer* killer);

	UFUNCTION()
	void Authority_OnIsWithinOtherSurvivorRangeChanged(AActor* survivorActor, const bool isInRange);

	UFUNCTION()
	void Authority_DeactivateInfection();

	UFUNCTION()
	void Authority_ActivateInfection();

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	AK26AttachedCrow();
};

FORCEINLINE uint32 GetTypeHash(const AK26AttachedCrow) { return 0; }
