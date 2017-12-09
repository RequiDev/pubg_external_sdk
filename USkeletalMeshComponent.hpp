#pragma once
#include "TArray.hpp"
#include "FTransform.hpp"

class USkeletalMeshComponent
{
public:
	FTransform GetBoneByIndex(int index) const;
	Vector3 GetBonePosition(int index) const;
	bool WasRecentlyRendered() const;
private:
	char __pad0x190[0x190];
	FTransform m_ComponentToWorld; // 0x30 size
	char __pad0x5D0[0x5D0];
	TArray<FTransform> m_ComponentSpaceTransformsArray;
	char __pad0xC3[0xC0];
	char m_bRecentlyRendered;
};
