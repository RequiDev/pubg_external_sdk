#pragma once
#include <cstdint>
#include <type_traits>
#include "../../memory/remote_process.hpp"

template<class T>
class TArray
{
public:
	int Length() const
	{
		return m_nCount;
	}

	bool IsValid() const
	{
		if (m_nCount > m_nMax)
			return false;
		if (!m_Data)
			return false;
		return true;
	}

	bool IsValidIndex(int32_t i) const
	{
		return i < m_nCount;
	}

	template<typename U = T>
	typename std::enable_if<std::is_pointer<U>::value, typename std::remove_pointer<U>::type>::type GetValue(int32_t index) const
	{
		auto offset = memory->read<uintptr_t>(m_Data + sizeof(uintptr_t) * index);
		return memory->read<typename std::remove_pointer<U>::type>(offset);
	}

	template<typename U = T>
	typename std::enable_if<!std::is_pointer<U>::value, U>::type GetValue(int32_t index) const
	{
		return memory->read<U>(m_Data + sizeof(U) * index);
	}

	template<typename U = T, typename std::enable_if<std::is_pointer<U>::value, int32_t>::type = 0>
	uintptr_t GetValuePtr(int32_t index) const
	{
		return memory->read<uintptr_t>(m_Data + sizeof(uintptr_t) * index);
	}

	template<typename U = T, typename std::enable_if<!std::is_pointer<U>::value, int32_t>::type = 0>
	uintptr_t GetValuePtr(int32_t index) const
	{
		return m_Data + sizeof(U) * index;
	}

	template<typename U = T>
	void SetValue(int32_t index, U value) const
	{
		return memory->write(this->GetValuePtr(index), value);
	}

	template<typename U = T>
	typename std::enable_if<std::is_pointer<U>::value, typename std::remove_pointer<U>::type>::type operator[](int32_t index) const
	{
		return GetValue<U>(index);
	}

	template<typename U = T>
	typename std::enable_if<!std::is_pointer<U>::value, U>::type operator[](int32_t index) const
	{
		return GetValue<U>(index);
	}
private:
	uintptr_t m_Data;
	int32_t m_nCount;
	int32_t m_nMax;
};
