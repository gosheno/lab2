#pragma once
class Field;
class Player;

class Event
{
public:
    virtual void init() = 0;
    virtual int get_speed() = 0;
    virtual void set_event_skin(char a) = 0;
    virtual char get_event_skin() = 0;
    virtual int get_HP() = 0;
    virtual int get_wall() = 0;
    virtual char get_skin() = 0;
    virtual char get_end() = 0;
    virtual void set_stat(int h, int s) = 0;
    virtual void set_skin(char a) = 0;
    virtual void set_wall() = 0;
    virtual void set_end() = 0;
    virtual void set_active() = 0;
    virtual bool get_active() = 0;
    virtual bool get_key() = 0;
    virtual Event* set_key() = 0;
    virtual void proc(Field& fl, Player& pl)=0;
};

