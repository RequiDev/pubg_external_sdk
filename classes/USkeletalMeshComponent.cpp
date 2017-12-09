#include "USkeletalMeshComponent.hpp"
#include "../pubg.hpp"

FTransform USkeletalMeshComponent::GetBoneByIndex(int index) const
{
	return this->m_ComponentSpaceTransformsArray[index];
}

Vector3 USkeletalMeshComponent::GetBonePosition(int index) const
{
	auto bone = this->GetBoneByIndex(index);

	auto mat = pubg::MatrixMultiplication(bone.ToMatrixWithScale(), this->m_ComponentToWorld.ToMatrixWithScale());
	return Vector3(mat._41, mat._42, mat._43);
}

bool USkeletalMeshComponent::WasRecentlyRendered() const
{
	return m_bRecentlyRendered & (1 << 3);
}