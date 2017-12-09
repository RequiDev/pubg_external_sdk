#include "UVehicleRiderComponent.hpp"
#include "AActor.hpp"

int UVehicleRiderComponent::GetSeatIndex() const
{
	return this->m_nSeatIndex;
}

AActor UVehicleRiderComponent::GetLastVehiclePawn() const
{
	return memory->read<AActor>(this->m_pLastVehiclePawn);
}
