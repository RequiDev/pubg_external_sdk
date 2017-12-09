#include "UGameInstance.hpp"
#include "../../memory/remote_process.hpp"

ULocalPlayer UGameInstance::GetLocalPlayer() const
{
	auto pLocalPlayer = memory->read<uintptr_t>(this->m_pULocalPlayer);
	return memory->read<ULocalPlayer>(pLocalPlayer);
}
