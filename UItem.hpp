#pragma once
#include "FText.hpp"

class UItem
{
public:
	std::string GetItemName() const;
private:
	char __pad0x40[0x40];
	uintptr_t m_ItemNameData;
};
