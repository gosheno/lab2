#pragma once
#include "Skin_finish.h"

Skin_finish::Skin_finish(){
	init();
}
void Skin_finish::init()
{
	set_skin('F');
	set_event_skin('F');
	set_end();
}