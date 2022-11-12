#pragma once
#include "level_1.h"

void Level_1::init() {
	set_active();
	set_event_skin('/');
}

void Level_1::set_level_map(Field& fl) {
	for (int x = 0; x < fl.X(); x++)
		for (int y = 0; y < fl.Y(); y++) fl.set_event(new Level_1, Point2D(x, y));
	Point2D key_pos = Point2D(fl.X() / 2, fl.Y() / 2);
	Point2D fin_pos = Point2D(rand() % (fl.X() - 1) + 1, rand() % (fl.Y() - 1) + 1);
	fl.set_event(new Skin_key, fin_pos);
	if (!(fin_pos == key_pos))fl.set_event(new Skin_finish, key_pos);
	else {
		Event* ev = new Skin_finish;
		(fl.set_event(ev->set_key(), fin_pos));
	}

}

void Level_1::proc(Field& fl, Player& pl)
{
	if (get_iter() == 0) {
 		int weight = fl.Y();
		int height = fl.X();
		Point2D vec = pl.point() - pl.get_last_move();
		if (!(pl.X() == 0 && pl.Y() == 0) &&
			!(pl.X() == 0 && pl.Y() == weight - 1) &&
			!(pl.X() == height - 1 && pl.Y() == 0) &&
			!(pl.X() == height - 1 && pl.Y() == weight - 1)) {

			if (vec.Y() == 0) {
				if (pl.Y() != weight - 1 && pl.X() != height - 1)
					if(pl.X() != 0)
					fl.set_event(new Skin_wall, Point2D(pl.X(), pl.Y() + 1));

				if (pl.Y() != 0 && pl.X() != 0)
					if (pl.X() != weight - 1)
					fl.set_event(new Skin_wall, Point2D(pl.X(), pl.Y() - 1));

			}

			if (vec.X() == 0) {

				if ((pl.X() != height - 1) && (pl.Y() != 0))
					if (pl.Y()  != 0)
					fl.set_event(new Skin_wall, Point2D(pl.X() + 1, pl.Y()));
				if ((pl.X() != 0))
					if (pl.Y()!= height - 1)
					fl.set_event(new Skin_wall, Point2D(pl.X() - 1, pl.Y()));
			}

			iter();
		}
	}
}

