#pragma once
#include "../../math/Vector.hpp"

class USceneComponent
{
public:
	Vector3 GetPosition() const;
	Vector3 GetVelocity() const;
	bool IsVisible() const;
private:
	char __pad0x168[0x168];
	char m_bVisible;
	char __pad0xB[0xB];
	Vector3 m_vecPosition;
	char __pad0xD4[0xD8];
	Vector3 m_vecVelocity;
};
