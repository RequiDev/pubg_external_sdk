#pragma once
#include "AActor.hpp"
#include "TArray.hpp"

class ULevel
{
public:
	TArray<AActor*> GetActors() const;
private:
	char __pad0xA0[0xA0];
	TArray<AActor*> m_Actors;
};
