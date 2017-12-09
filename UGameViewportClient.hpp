#pragma once
#include <cstdint>

class UGameViewportClient
{
public:
	class UWorld GetWorld() const;
private:
	char __pad0x80[0x80];
	uintptr_t m_pUWorld;
};
