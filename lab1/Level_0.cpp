#include "Level_0.h"
#include "Trap.h"
void Level_0::proc(Field& fl, Player& pl)
{
	iter();
}

void Level_0::init() {
	set_skin(' ');
	set_limit_req(Point2D(-1, -1));
}

void Level_0::set_level_map( Field& fl) {
	fl.set_event(new Skin_bomb, Point2D(1, 0));
	fl.set_event(new Skin_player_esc, Point2D(1, 2));
	fl.set_event(new Skin_wall, Point2D(1, 3));
	fl.set_event(new Skin_player_speedup, Point2D(1, 4));
	fl.set_event(new Skin_bomb, Point2D(1, 6));
	fl.set_event(new Trap, Point2D(4, 4));
	Event* fn = new Skin_finish;
	fn->set_key();
	fl.set_event(fn, Point2D(1, 8));
}