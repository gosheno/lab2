#pragma once
#include "Skin_player_speedup.h"

Skin_player_speedup::Skin_player_speedup() {
	init();
}

void Skin_player_speedup::init() {
	set_stat(0, 1);
	set_event_skin('S');
}