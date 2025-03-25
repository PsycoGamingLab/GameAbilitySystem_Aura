// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/TargetDataunderMouse.h"

#include "AbilitySystemComponent.h"


UTargetDataunderMouse* UTargetDataunderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataunderMouse* MyObj = NewAbilityTask<UTargetDataunderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataunderMouse::Activate()
{
	const bool bIsLocallyControlled = Ability->GetCurrentActorInfo()->IsLocallyControlled();
	if(bIsLocallyControlled)
	{
		SendMouseCursorData();
	}

}

void UTargetDataunderMouse::SendMouseCursorData()
{
	FScopedPredictionWindow ScopedPrediction(AbilitySystemComponent.Get());
	APlayerController* PC = Ability->GetCurrentActorInfo()->PlayerController.Get();
	FHitResult CursorHit;
	PC->GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	
	FGameplayAbilityTargetDataHandle DataHandle;
	FGameplayAbilityTargetData_SingleTargetHit* Data =new FGameplayAbilityTargetData_SingleTargetHit();

	Data->HitResult = CursorHit;
	DataHandle.Add(Data);

	AbilitySystemComponent->ServerSetReplicatedTargetData(
		GetAbilitySpecHandle(),
		GetActivationPredictionKey(),
		DataHandle,
		FGameplayTag(),
		AbilitySystemComponent->ScopedPredictionKey);

	if(ShouldBroadcastAbilityTaskDelegates())
	{
		ValidData.Broadcast(DataHandle);
	}
}
