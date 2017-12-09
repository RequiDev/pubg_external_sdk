#pragma once
#include "../../math/Vector.hpp"

struct FMinimalViewInfo
{
	class Vector3	Location;
	class Vector3	Rotation;
	float			FOV;
	float			OrthoWidth;
	float			OrthoNearClipPlane;
	float			OrthoFarClipPlane;
	float			AspectRatio;
};

struct FCameraCacheEntry
{
	float					TimeStamp;
	unsigned char			UnknownData00[0xC];
	struct FMinimalViewInfo	POV;
};