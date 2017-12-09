#pragma once
#define _USE_MATH_DEFINES // for C++  
#include <cmath>
#include "Vector.hpp"
#include <d3d9.h>

// credits to Striekcarl for some methods
class FRotator
{
public:
	float pitch, yaw, roll;

	FRotator() : pitch(0.0f), yaw(0.0f), roll(0.0f){}
	FRotator(float _pitch, float _yaw, float _roll)
	{
		pitch = _pitch;
		yaw = _yaw;
		roll = _roll;
	}

	FRotator(const Vector3& vec)
	{
		static constexpr auto RADPI = static_cast<float>(180 / 3.14159265358979323846);
		yaw = static_cast<float>(atan2(vec.y, vec.x)) * RADPI;
		pitch = static_cast<float>(atan2(vec.z, sqrt((vec.x * vec.x) + (vec.y * vec.y)))) * RADPI;
		roll = 0;
	}

	FLOAT length() const
	{
		return abs(sqrt(pitch*pitch + yaw*yaw + roll*roll));
	}

	FRotator clamp() const
	{
		auto result = *this;

		while (result.pitch > 180.0f)
			result.pitch -= 360.0f;

		while (result.pitch < -180.0f)
			result.pitch += 360.0f;

		while (result.yaw < -180.0f)
			result.yaw += 360.0f;

		while (result.yaw > 180.0f)
			result.yaw -= 360.0f;

		if (result.pitch < -89.f)
			result.pitch = -89.f;

		if (result.pitch > 89.f)
			result.pitch = 89.f;

		result.roll = 0;

		return result;
	}

	void get_axes(Vector3& x, Vector3&y, Vector3& z) const
	{
		auto m = to_matrix();

		x = Vector3(m._11, m._12, m._13);
		y = Vector3(m._21, m._22, m._23);
		z = Vector3(m._31, m._32, m._33);
	}

	D3DMATRIX to_matrix(const Vector3& origin = {0.0f, 0.0f, 0.0f}) const
	{
		auto radPitch = static_cast<float>(pitch * 3.14159265358979323846 / 180.f);
		auto radYaw = static_cast<float>(yaw * 3.14159265358979323846 / 180.f);
		auto radRoll = static_cast<float>(roll * 3.14159265358979323846 / 180.f);

		auto SP = static_cast<float>(sin(radPitch));
		auto CP = static_cast<float>(cos(radPitch));
		auto SY = static_cast<float>(sin(radYaw));
		auto CY = static_cast<float>(cos(radYaw));
		auto SR = static_cast<float>(sin(radRoll));
		auto CR = static_cast<float>(cos(radRoll));

		D3DMATRIX m;

		m.m[0][0] = CP * CY;
		m.m[0][1] = CP * SY;
		m.m[0][2] = SP;
		m.m[0][3] = 0.f;

		m.m[1][0] = SR * SP * CY - CR * SY;
		m.m[1][1] = SR * SP * SY + CR * CY;
		m.m[1][2] = -SR * CP;
		m.m[1][3] = 0.f;

		m.m[2][0] = -(CR * SP * CY + SR * SY);
		m.m[2][1] = CY * SR - CR * SP * SY;
		m.m[2][2] = CR * CP;
		m.m[2][3] = 0.f;

		m.m[3][0] = origin.x;
		m.m[3][1] = origin.y;
		m.m[3][2] = origin.z;
		m.m[3][3] = 1.f;
		return m;
	}

	bool operator ==(const FRotator& o) const
	{
		return pitch == o.pitch && yaw == o.yaw && roll == o.roll;
	}

	bool operator !=(const FRotator& o) const
	{
		return !(*this == o);
	}

	FRotator& operator+(const FRotator& o)
	{
		pitch += o.pitch;
		yaw += o.yaw;
		roll += o.roll;
		return *this;
	}
	FRotator& operator-(const FRotator& o)
	{
		pitch -= o.pitch;
		yaw -= o.yaw;
		roll -= o.roll;
		return *this;
	}
	FRotator& operator*(const FRotator& o)
	{
		pitch *= o.pitch;
		yaw *= o.yaw;
		roll *= o.roll;
		return *this;
	}
	FRotator& operator/(const FRotator& o)
	{
		pitch /= o.pitch;
		yaw /= o.yaw;
		roll /= o.roll;
		return *this;
	}

	FRotator& operator+(float o)
	{
		pitch += o;
		yaw += o;
		roll += o;
		return *this;
	}
	FRotator& operator-(float o)
	{
		pitch -= o;
		yaw -= o;
		roll -= o;
		return *this;
	}
	FRotator& operator*(float o)
	{
		pitch *= o;
		yaw *= o;
		roll *= o;
		return *this;
	}
	FRotator& operator/(float o)
	{
		pitch /= o;
		yaw /= o;
		roll /= o;
		return *this;
	}

	operator Vector3() const
	{
		auto radPitch = static_cast<float>(pitch * 3.14159265358979323846 / 180.f);
		auto radYaw = static_cast<float>(yaw * 3.14159265358979323846 / 180.f);

		auto SP = static_cast<float>(sin(radPitch));
		auto CP = static_cast<float>(cos(radPitch));
		auto SY = static_cast<float>(sin(radYaw));
		auto CY = static_cast<float>(cos(radYaw));

		return Vector3(CP * CY, CP * SY, SP);
	}
};
