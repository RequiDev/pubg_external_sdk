#include "UWorld.hpp"
#include "../../memory/remote_process.hpp"

ULevel UWorld::GetLevel() const
{
	return memory->read<ULevel>(this->m_pULevel);
}

UGameInstance UWorld::GetGameInstance() const
{
	return memory->read<UGameInstance>(this->m_pGameInstance);
}
