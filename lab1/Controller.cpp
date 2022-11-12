#include "Controller.h"

Controller::Controller(Point2D seti)
{
    end = false;
    Mediator m(seti);
    this->medi = m;
    this->level = m.get_level();

    if (!(level->get_limit_req() == Point2D(-1, -1)))
        this->limit = m.get_settings_info(level->get_limit_req());
    else this->limit = level->get_limit();

    Player pl(limit);
    this->player = pl;

    player.receiver_add(&field);

    field.init_map(limit);
    level->set_level_map(field);

    receiver_add(&player);
    receiver_add(&field);
}

bool Controller::player_make_step(Printer &pr, int x)
{
    if (!x) {
        Point2D last = player.get_last_move();

        char w = medi.read_move();
        medi.get_step_comand(w);

        //field.set_event(field.get_map()[last.X()][last.Y()].get_event(), player.get_last_move());

        if (medi.get_move() == 'e') { set_end(); }
        player.step(medi.get_step_comand());
        if (player.point() == player.get_last_move()) return check_player_HP();
   }
    else {

        player.step();
    }

    Event* ev = field.get_map(player.X(), player.Y()).get_event();
    if (ev->get_active()) {
        ev->proc(field, player);
    }
    player.update(ev);
    if (ev->get_wall()) {
        pr.add("I can't cross it...");
        player.step_back();
    }
    if (ev->get_end() && player.get_key()) {
        set_end();
    }
    else if (ev->get_end() && !player.get_key()) {
        pr.add("no key no gale");
    }
    return check_player_HP();
}


Point2D Controller::get_limit() {
    return this->limit;
}

Field Controller::get_field()
{
    return field;
}


bool Controller::check_player_HP()
{
    if (player.get_HP() <= 0) {
        player.set_HP(0);
        return true;
    }
    if (player.get_HP() > 100) { player.set_HP(100); }
    return false;
}

void Controller::set_end()
{
    end = true;
}

bool Controller::get_end()
{
    return end;
}

Player Controller::get_player()
{
    return player;
}

Mediator Controller::get_mediator()
{
    return medi;
}

Field& Controller::Field_link() {
    Field& ret = this->field;
    return ret;
}

Player& Controller::player_link()
{
    Player& ret = this->player;
    return ret;
}
Printer Controller::get_log() {
     return take_log();
}

 