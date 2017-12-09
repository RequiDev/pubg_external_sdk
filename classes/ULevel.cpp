#include "ULevel.hpp"

TArray<AActor*> ULevel::GetActors() const
{
	return this->m_Actors;
}