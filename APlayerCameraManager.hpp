#pragma once
#include "FCameraCacheEntry.hpp"

class APlayerCameraManager
{
public:
	const FCameraCacheEntry& GetCameraCache() const;
private:
	char __pad0x410[0x410];
	FCameraCacheEntry m_CameraCacheEntry;
};
