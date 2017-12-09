#pragma once
#include "UGameInstance.hpp"
#include "ULevel.hpp"

class UWorld
{
public:
	ULevel GetLevel() const;
	UGameInstance GetGameInstance() const;
private:
	char __pad0x30[0x30];
	uintptr_t m_pULevel;
	char __pad0x108[0x108];
	uintptr_t m_pGameInstance;
};
