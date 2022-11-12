#pragma once
#include "Printer.h"
#include "Level.h"
#include "Point2D.h"
#include "Player.h"
#include "Field.h"
#include "Mediator.h"
#include "AObserver_sender.h"
#include "IObserver_receiver.h"
class Controller: public AObserver_sender, public IObserver_receiver{
private:
    Mediator medi;
    Field field;
    Player player;
    Point2D limit;
    Level *level;
    bool end;
public:
    Controller(Point2D seti = Point2D(0, 0));
    bool player_make_step(Printer &pr, int x = 0);
    bool check_player_HP();
    void set_end();
    bool get_end();
    Field get_field();
    Player get_player();
    Mediator get_mediator();
    Point2D get_limit();
    Field& Field_link();
    Player& player_link();
    Printer get_log() override;
};