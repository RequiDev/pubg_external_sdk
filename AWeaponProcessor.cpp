#include "AWeaponProcessor.hpp"

TArray<ATslWeapon*> AWeaponProcessor::GetEquippedWeapons() const
{
	return this->m_EquippedWeapons;
}

ATslWeapon AWeaponProcessor::GetCurrentWeapon() const
{
	return this->m_EquippedWeapons[this->m_nCurrentWeaponIndex];
}

int AWeaponProcessor::GetCurrentWeaponIndex() const
{
	return this->m_nCurrentWeaponIndex;
}
