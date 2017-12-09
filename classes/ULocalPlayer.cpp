#include "ULocalPlayer.hpp"
#include "../../memory/remote_process.hpp"

uintptr_t ULocalPlayer::GetPlayerControllerPtr() const
{
	return this->m_pPlayerController;
}

APlayerController ULocalPlayer::GetPlayerController() const
{
	return memory->read<APlayerController>(this->m_pPlayerController);
}

UGameViewportClient ULocalPlayer::GetViewportClient() const
{
	return memory->read<UGameViewportClient>(this->m_pViewportClient);
}

Vector3 ULocalPlayer::GetPosition() const
{
	return this->m_vecPosition;
}

void ULocalPlayer::SetRotation(const FRotator& rot) const
{
	memory->write(this->m_pPlayerController + 0x03D0, rot);
}