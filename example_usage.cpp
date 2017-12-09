#include "classes/AActor.hpp"
#include "classes/UWorld.hpp"

void example()
{
	auto tmp_world = memory->read<UWorld>(memory->read<uintptr_t>(base + pubg::addresses.world));
	auto world = tmp_world.GetGameInstance().GetLocalPlayer().GetViewportClient().GetWorld();
	auto uLocalPlayer = world.GetGameInstance().GetLocalPlayer();
	auto player_controller = uLocalPlayer.GetPlayerController();
	player_controller.SetPlayerSpeed(settings::player_speed);
	auto localplayer = player_controller.GetLocalPlayer();
	auto level = world.GetLevel();

	auto actors = level.GetActors();
	if (!actors.IsValid())
		return;
	
	auto cameracache = player_controller.GetPlayerCameraManager().GetCameraCache();
	
	for (auto i = 0; i < max_entities; i++)
	{
		auto actor = actors[i];
		if (actor == localplayer)
			continue;

		auto id = actor.GetID();
		auto pos = actor.GetRootComponent().GetPosition();
		auto distance = cameracache.POV.Location.Distance(pos) / 100.00f;

		Vector2 screen;
		if (!world_to_screen(pos, &screen))
			continue;
		
		overlay->draw_text(screen, ...);
	}
}