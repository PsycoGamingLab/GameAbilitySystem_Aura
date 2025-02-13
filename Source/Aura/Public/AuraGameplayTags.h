// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *  Aura Gameplay Tags
 *
 *  Singleton contain ing native Gameplay tags
 */

struct FAuraGameplayTags
{
public:

 static const FAuraGameplayTags& Get() {return GameplayTags;}
 static void InitializeNativeGameplayTags();

protected:
private:
 static FAuraGameplayTags GameplayTags;
};

