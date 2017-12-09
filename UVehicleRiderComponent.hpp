#pragma once
#include <cstdint>

class AActor;

class UVehicleRiderComponent
{
public:
	int GetSeatIndex() const;
	AActor GetLastVehiclePawn() const;
private:
	char __pad0x100[0x100];
	int m_nSeatIndex;
	char __pad0x3C[0x3C];
	uintptr_t m_pLastVehiclePawn;
};
