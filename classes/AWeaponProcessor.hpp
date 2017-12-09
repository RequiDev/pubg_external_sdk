#pragma once
#include "TArray.hpp"
#include "ATslWeapon.hpp"

class AWeaponProcessor
{
public:
	TArray<ATslWeapon*> GetEquippedWeapons() const;
	ATslWeapon GetCurrentWeapon() const;
	int GetCurrentWeaponIndex() const;
private:
	char __pad0x438[0x438];
	TArray<ATslWeapon*> m_EquippedWeapons;
	int m_nCurrentWeaponIndex;
};
