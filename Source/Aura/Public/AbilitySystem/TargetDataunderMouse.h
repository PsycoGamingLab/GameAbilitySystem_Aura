// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "TargetDataunderMouse.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseDataTargetSignature,const FGameplayAbilityTargetDataHandle&,DataHandle);

/**
 * 
 */
UCLASS()
class AURA_API UTargetDataunderMouse : public UAbilityTask
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category = "Ability|Task",meta = (DisplayName = "TargetDataUnderMouse",HidePin = "OwningAbility",DefaultToSelf= "OwningAbility",BlueprintInternalUseOnly="true"))
	static UTargetDataunderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);

	UPROPERTY(BlueprintAssignable)
	FMouseDataTargetSignature ValidData;

private:
	virtual void Activate() override;
	void SendMouseCursorData();
};
