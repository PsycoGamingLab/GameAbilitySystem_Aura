// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/CharacterClassInfo.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category="Aura Ability System Library|Widget Controller")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Aura Ability System Library|Widget Controller")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|Character Class Defaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject,ECharacterClass CharacterClass,float Level,UAbilitySystemComponent* ASC);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|Character Class Defaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject,UAbilitySystemComponent* ASC,ECharacterClass CharacterClass);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|Character Class Defaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Aura Ability System Library|GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintPure, Category="Aura Ability System Library|GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockHit);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref) FGameplayEffectContextHandle& EffectContextHandle, bool bInIsCriticalHit);

	UFUNCTION(BlueprintCallable, Category="Aura Ability System Library|GameplayMechanics")
	static void GetLivePlayersWithinRadius(const UObject* WorldContextObject,TArray<AActor*>& OutOverlappingActors,const TArray<AActor*>& ActorsToIgnore, float Radius,const FVector& SphereOrigin);
};
