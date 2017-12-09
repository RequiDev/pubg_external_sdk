#pragma once
#include "FWeaponData.hpp"
#include "FWeaponGunAnim.hpp"
#include "FWeaponGunData.hpp"
#include "FRecoilInfo.hpp"
#include "FTrajectoryWeaponData.hpp"
#include "FWeaponDeviationData.hpp"

enum EWeaponClass : byte
{
	Class_Pistol = 0,
	Class_SMG = 1,
	Class_Rifle = 2,
	Class_Carbine = 3,
	Class_Shotgun = 4,
	Class_Sniper = 5,
	Class_DMR = 6,
	Class_LMG = 7,
	Class_Melee = 8,
	Class_Throwable = 9,
	Class_MAX = 10
};

class ATslWeapon
{
	char __pad0x538[0x538];
public:
	FWeaponData				WeaponConfig; // 0x90
private:
	char __pad0x270[0x298];
public:
	FWeaponGunData			WeaponGunConfig;
	FWeaponDeviationData	WeaponDeviationConfig;
	FWeaponGunAnim			WeaponGunAnim;
	float					TrajectoryGravityZ;                                       // 0x0A20(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					RecoilSpreadScale;                                        // 0x0A24(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	unsigned char			FireAtViewPoint : 1;                                      // 0x0A28(0x0001) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					DefaultTimerFrequency;                                    // 0x0A2C(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					CrouchSpreadModifier;                                     // 0x0A30(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					ProneSpreadModifier;                                      // 0x0A34(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					WalkSpread;                                               // 0x0A38(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					RunSpread;                                                // 0x0A3C(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	float					JumpSpread;                                               // 0x0A40(0x0004) (CPF_ZeroConstructor, CPF_Config, CPF_IsPlainOldData)
	FTrajectoryWeaponData	TrajectoryConfig;                                         // 0x0A48(0x0060) (CPF_Edit, CPF_DisableEditOnInstance)
	FRecoilInfo				RecoilInfo;                                               // 0x0AA8(0x0068) (CPF_Edit, CPF_DisableEditOnInstance)
	uintptr_t				ImpactTemplate;                                           // 0x0B10(0x0008) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	uintptr_t				TrailFX;                                                  // 0x0B18(0x0008) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	char					TrailTargetParam[8];                                         // 0x0B20(0x0008) (CPF_Edit, CPF_ZeroConstructor, CPF_DisableEditOnInstance, CPF_IsPlainOldData)
	unsigned char			UnknownData00[0x18];                                      // 0x0B28(0x0018) MISSED OFFSET
	float					WeaponSpread;                                             // 0x0B40(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	float					RecoilModifier_Stand;                                     // 0x0B44(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	float					RecoilModifier_Crouch;                                    // 0x0B48(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	float					RecoilModifier_Prone;                                     // 0x0B4C(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	float					VerticalRecoilMin;                                        // 0x0B50(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	float					VerticalRecoilMax;                                        // 0x0B54(0x0004) (CPF_Net, CPF_ZeroConstructor, CPF_Transient, CPF_IsPlainOldData)
	unsigned char			UnknownData01[0x48];                                      // 0x0B58(0x0048) MISSED OFFSET
};
