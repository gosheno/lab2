#pragma once
#include"Event.h"

class Skin: public Event{
private:
    int speedup_info;
    int HP_info;
    char skin;
    char event_skin;
    bool end;
    bool wall;
    bool active;
    bool key;
public:
    Skin();
    int get_speed()override;
    virtual void init()override;
    void set_event_skin(char a)override;
    char get_event_skin()override;
    int get_HP()override;
    int get_wall()override;
    char get_skin()override;
    char get_end()override;
    bool get_key()override;
    Event* set_key()override;
    void set_stat(int h, int s)override;
    void set_skin(char a)override;
    void set_wall()override;
    void set_end()override;
    void set_active()override;
    bool get_active()override;
    void proc(Field& fl, Player& pl) override;
};