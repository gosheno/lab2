#include "Cell.h"

Cell::Cell(Event* ev, Point2D po): cell_event(ev) {
	point(po);
	cell_skin = ev->get_event_skin();
	wall = ev->get_wall();
}

void Cell::event_free() {
	delete cell_event;
	cell_event = nullptr;
}

char Cell::get_skin()
{
	return cell_skin;
}

bool Cell::get_wall() {
	return wall;
}
void Cell::set_event(Event* ev)
{
	this->cell_event = ev;
	this->cell_skin = ev->get_event_skin();
}

Event* Cell::get_event() {
	return cell_event;
}


void Cell::upd()
{
	wall = cell_event->get_wall();
	if (wall)
		cell_skin = cell_event->get_event_skin();
	else cell_skin = cell_event->get_skin();
}

void Cell::upd_out() {
	cell_skin = cell_event->get_event_skin();
}

void Cell::set_wall() {
	wall = true;
}

Printer Cell::get_log(){
	Printer res;
	res.add("<cell>\nPossition: ");
	res.add(point().point_to_string());
	res.add("\nEvent: ");
	res.add(typeid(*cell_event).name());
	return res;
}