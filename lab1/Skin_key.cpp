#pragma once
#include "Skin_key.h"

Skin_key::Skin_key() {
	init();
}
void Skin_key::init()
{
	set_skin('P');
	set_event_skin('K');
	set_key();
}