#include "FText.hpp"
#include "../../memory/remote_process.hpp"
#include <iostream>

std::string FTextData::GetName() const
{
	wchar_t entityname[128] = { 0 };
	memory->read_array(this->m_pName, entityname, sizeof entityname);
	std::wstring ws(entityname);
	std::string ret(ws.begin(), ws.end());
	return ret;
}