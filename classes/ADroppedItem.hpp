#pragma once
#include "../../math/Vector.hpp"
#include "UItem.hpp"

class ADroppedItem
{
public:
	Vector3 GetRelativePosition() const;
	UItem GetItem() const;
private:
	char __pad0x1E0[0x1E0];
	Vector3 m_vecRelativePosition;
	char __pad0x25C[0x25C];
	uintptr_t m_pUItem;
};
