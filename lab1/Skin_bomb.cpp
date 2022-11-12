#include "Skin_bomb.h"

Skin_bomb::Skin_bomb() {
	init();
}

void Skin_bomb::init()
{
	set_stat(-50, 0);
	set_event_skin('@');
}