#include "Trap.h"
void Trap::proc(Field& fl, Player& pl) {
	if (get_iter() == 0) {
		int weight = fl.Y();
		int height = fl.X();

		if (pl.X() < weight && pl.Y() < height && pl.X() > 0 && pl.Y() > 0) {
			fl.set_event(new Skin_bomb, Point2D(pl.X() + 1, pl.Y()));
			fl.set_event(new Skin_bomb, Point2D(pl.X() - 1, pl.Y()));
			fl.set_event(new Skin_bomb, Point2D(pl.X(), pl.Y()+1));
			fl.set_event(new Skin_bomb, Point2D(pl.X(), pl.Y()-1));
		}
	}
	iter();
}

void Trap::init() {
	set_active();
	set_event_skin('T');
	set_limit_req(Point2D(5, 5));
}

void Trap::set_level_map(Field& fl) {}