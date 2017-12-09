#include "USceneComponent.hpp"

Vector3 USceneComponent::GetPosition() const
{
	return this->m_vecPosition;
}

Vector3 USceneComponent::GetVelocity() const
{
	return this->m_vecVelocity;
}

bool USceneComponent::IsVisible() const
{
	return this->m_bVisible & (1 << 7);
}
