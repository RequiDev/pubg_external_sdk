#include "UItem.hpp"
#include "../../memory/remote_process.hpp"

std::string UItem::GetItemName() const
{
	return memory->read<FTextData>(this->m_ItemNameData).GetName();
}
