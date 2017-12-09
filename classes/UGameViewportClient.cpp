#include "UGameViewportClient.hpp"
#include "UWorld.hpp"
#include "../../memory/remote_process.hpp"

UWorld UGameViewportClient::GetWorld() const
{
	return memory->read<UWorld>(this->m_pUWorld);
}
