#pragma once
#include <cstdint>
#include <string>

class FTextData
{
public:
	std::string GetName() const;
private:
	char __pad0x028[0x28];
	uintptr_t m_pName;
	int m_nLength;
};