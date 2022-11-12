#pragma once
#include "Cell.h"
#include "Point2D.cpp"
#include "IObserver_receiver.h"
#include "AObserver_sender.h"
class Field :public IObserver_receiver, public AObserver_sender{
private:
    std::vector<std::vector<Cell>> map;
    Point2D settings;
    std::vector<Cell*> data_history;
public:
    void updtx(Point2D pos)override;
    Field();
    Cell get_map(int x, int y);
    Field(const Field& other);
    void operator=(const Field& other);
    //Event* update_field(Point2D pos);
    void init_map(std::vector<std::vector<Cell>> fi);
    void init_map(Point2D seti);
    ~Field();
    void field_free();
    void set_event(Event* ev, Point2D pos);
    void set_cell(Cell a);
    std::vector<std::vector<Cell>> get_map();
    Event* update_field(Point2D pos = Point2D(0, 0));
    Printer get_log();
};

