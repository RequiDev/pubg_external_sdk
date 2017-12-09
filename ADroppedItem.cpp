#include "ADroppedItem.hpp"
#include "../../memory/remote_process.hpp"

Vector3 ADroppedItem::GetRelativePosition() const
{
	return this->m_vecRelativePosition;
}

UItem ADroppedItem::GetItem() const
{
	return memory->read<UItem>(this->m_pUItem);
}
