#pragma once
#include <cstdint>
#include "APlayerController.hpp"
#include "UGameViewportClient.hpp"

class ULocalPlayer
{
public:
	uintptr_t GetPlayerControllerPtr() const;
	APlayerController GetPlayerController() const;
	UGameViewportClient GetViewportClient() const;
	Vector3 GetPosition() const;
	void SetRotation(const FRotator& rot) const;
private:
	char __pad0x30[0x30];
	uintptr_t m_pPlayerController;
	char __pad0x20[0x20];
	uintptr_t m_pViewportClient;
	char __pad0x10[0x10];
	Vector3 m_vecPosition;
};