#include "aactor.hpp"
#include "../../memory/remote_process.hpp"

int AActor::GetID() const
{
	return this->m_nID;
}

USceneComponent AActor::GetRootComponent() const
{
	return memory->read<USceneComponent>(this->m_pRootComp);
}

uintptr_t AActor::GetDroppedItems() const
{
	return this->m_DroppedItemsArray;
}

int AActor::GetDroppedItemsCount() const
{
	return this->m_nDroppedItemsCount;
}

USkeletalMeshComponent AActor::GetSkeletalMeshComponent() const
{
	return memory->read<USkeletalMeshComponent>(this->m_pMesh);
}

AWeaponProcessor AActor::GetWeaponProcessor() const
{
	return memory->read<AWeaponProcessor>(this->m_pWeaponProcessor);
}

bool AActor::InMyTeam() const
{
	return this->m_pTeam;
}

float AActor::GetHealth() const
{
	return this->m_flHealth;
}

float AActor::GetMaxHealth() const
{
	return this->m_flMaxHealth;
}

float AActor::GetGroggyHealth() const
{
	return this->m_flGroggyHealth;
}

UVehicleRiderComponent AActor::GetVehicleRiderComponent() const
{
	return memory->read<UVehicleRiderComponent>(this->m_pVehicleRiderComponent);
}

TArray<UItem*> AActor::GetItems() const
{
	return this->m_Items;
}

uintptr_t AActor::GetPunchDistanceOffset()
{
	return offsetof(AActor, m_flPunchDistance);
}
