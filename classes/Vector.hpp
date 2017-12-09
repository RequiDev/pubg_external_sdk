#pragma once
#define _USE_MATH_DEFINES // for C++  
#include <cmath>

class Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f) { }

	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

	float x;
	float y;
	float z;

	float Dot(const Vector3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Distance(const Vector3& v) const
	{
		return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	Vector3 operator+(const Vector3& v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(const Vector3& v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(float v) const
	{
		return Vector3(x * v, y * v, z * v);
	}

	bool operator==(const Vector3& v) const
	{
		return x == v.x && y == v.y &&  z == v.z;
	}

	bool operator!=(const Vector3& v) const
	{
		return !(*this == v);
	}
};
