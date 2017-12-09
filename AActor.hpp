#pragma once
#include <cstdint>
#include "USceneComponent.hpp"
#include "USkeletalMeshComponent.hpp"
#include "AWeaponProcessor.hpp"
#include "UVehicleRiderComponent.hpp"
#include "UItem.hpp"

class AActor
{
public:
	int GetID() const;
	USceneComponent GetRootComponent() const;
	uintptr_t GetDroppedItems() const;
	int GetDroppedItemsCount() const;
	USkeletalMeshComponent GetSkeletalMeshComponent() const;
	AWeaponProcessor GetWeaponProcessor() const;
	bool InMyTeam() const;
	float GetHealth() const;
	float GetMaxHealth() const;
	float GetGroggyHealth() const;
	UVehicleRiderComponent GetVehicleRiderComponent() const;
	TArray<UItem*> GetItems() const;
	static uintptr_t GetPunchDistanceOffset();

	operator bool() const
	{
		return m_nID != 0;
	}
	bool operator==(const AActor& rhs) const
	{
		return m_pRootComp == rhs.m_pRootComp;
	}
	bool operator!=(const AActor& rhs) const 
	{
		return m_pRootComp != rhs.m_pRootComp;
	}
private:
	char __pad0x18[0x18];
	int m_nID;
	char __pad0x180[0x164];
	uintptr_t m_pRootComp;
	char __pad0x150[0x150];
	uintptr_t m_DroppedItemsArray;
	int m_nDroppedItemsCount;
	char __pad0x11C[0x11C];
	uintptr_t m_pMesh;
	char __pad0xC8[0xC8];
	TArray<UItem*> m_Items;
	char __pad0x508[0x508];
	uintptr_t m_pWeaponProcessor;
	char __pad0x78[0x78];
	float m_flPunchDistance;
	char __pad0x21C[0x21C];
	uintptr_t m_pTeam;
	char __pad0x3EC[0x3EC];
	float m_flHealth;
	float m_flMaxHealth;
	float m_flGroggyHealth;
	char __pad0xF8[0xF8];
	uintptr_t m_pVehicleRiderComponent;
};
