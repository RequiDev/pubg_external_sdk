#include "APlayerController.hpp"
#include "../../memory/remote_process.hpp"

FRotator APlayerController::GetControlRotation() const
{
	return this->m_ControlRotation;
}

AActor APlayerController::GetLocalPlayer() const
{
	return memory->read<AActor>(this->m_pLocalPlayer);
}

uintptr_t APlayerController::GetLocalPlayerPtr() const
{
	return this->m_pLocalPlayer;
}

APlayerCameraManager APlayerController::GetPlayerCameraManager() const
{
	return memory->read<APlayerCameraManager>(this->m_pPlayerCameraManager);
}

void APlayerController::SetPlayerSpeed(float speed) const
{
	if (this->m_pPawn)
		memory->write(this->m_pPawn + 0x98, speed);
}
