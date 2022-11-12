#pragma once
#include "Skin_wall.h"

void Skin_wall::init()
{
	set_stat(-10, 0);
	set_wall();
	set_event_skin('#');
	set_skin('#');
}
