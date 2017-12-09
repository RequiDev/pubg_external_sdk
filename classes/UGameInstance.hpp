#pragma once
#include "ULocalPlayer.hpp"
#include <cstdint>

class UGameInstance
{
public:
	ULocalPlayer GetLocalPlayer() const;
private:
	char __pad0x38[0x38];
	uintptr_t m_pULocalPlayer;
};