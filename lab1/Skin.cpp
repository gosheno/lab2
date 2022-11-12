#pragma once
#include "Skin.h"

Skin::Skin(){
    init();
}

void Skin::init() {
    set_stat(0, 0);
    this->skin = 'P';
    this->event_skin = '.';
    this->wall = 0;
    this->end = false;
    this->active = false;
    this->key = false;
};

void Skin::set_active() {
    active = true;
}
bool Skin::get_active() {
    return active;
}
int Skin::get_speed()
{
    return speedup_info;
}

void Skin::set_event_skin(char a)
{
    event_skin = a;
}

char Skin::get_event_skin()
{
    return event_skin;
}

int Skin::get_HP()
{
    return HP_info;
}

int Skin::get_wall()
{
    return this->wall;
}

char Skin::get_skin()
{
    return this->skin;
}
char Skin::get_end() {
    return end;
}

void Skin::set_stat(int h, int s)
{
    this->HP_info = h;
    this->speedup_info = s;
}

void Skin::set_skin(char a)
{
    this->skin = a;
}

void Skin::set_wall()
{
    wall = true;
}

void Skin::set_end()
{
    end = true;
}
bool Skin::get_key() { return key; }
Event* Skin::set_key() { key = true;
return this;
}
void Skin::proc(Field& fl, Player& pl) {}

