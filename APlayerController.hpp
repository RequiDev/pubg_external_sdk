#pragma once
#include "APlayerCameraManager.hpp"
#include "AActor.hpp"
#include <cstdint>
#include "../../math/FRotator.hpp"

class APlayerController
{
public:
	FRotator GetControlRotation() const;
	AActor GetLocalPlayer() const;
	uintptr_t GetLocalPlayerPtr() const;
	APlayerCameraManager GetPlayerCameraManager() const;
	void SetPlayerSpeed(float speed) const;
private:
	char __pad0x3D0[0x3A8];
	uintptr_t m_pPawn;
	char __pad0x20[0x20];
	FRotator m_ControlRotation;
	char __pad0x3C[0x3C];
	uintptr_t m_pLocalPlayer;
	char __pad0x18[0x18];
	uintptr_t m_pPlayerCameraManager;
};
