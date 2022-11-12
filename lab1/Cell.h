#pragma once
#include <typeinfo>
#include "Printer.h"
#include "Point2D.h"
#include "Event.h"


class Cell :
    public Point2D
{
private:
    Event* cell_event;
    char cell_skin;
    bool wall;
public:
    Cell():cell_event(nullptr),cell_skin(' '), wall(false) {}
    Cell(Event* ev, Point2D po = Point2D());
    char get_skin();
    void event_free();
    void set_event(Event* ev);
    Event* get_event();
    void upd();
    void upd_out();
    void set_wall();
    bool get_wall();
    Printer get_log();
}; 

