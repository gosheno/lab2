#pragma once
#include "Player.h"

Player::Player(Point2D lim):HP(100), speed(1), key(false), setti(lim)
{
	point(0, 0);
}

void Player::step(Point2D move)
{
	last_move = point();
	Point2D curent = Point2D(move * speed + last_move);
	point(curent);
	check_pos();
	notify_movement();
}
void Player::step_back() {
	point(last_move);
	notify_movement();
	
}

void Player::take_HP(int h)
{
	this->HP += h;
}

void Player::take_speed(int s)
{
	this->speed += s;
	   
}

Point2D Player::get_last_move()
{
	return this->last_move;
	
}

void Player::get_stat_info()
{
	std::cout << "HP = " << HP << std::endl;
    std::cout << "speed = " << speed << std::endl;
	std::cout << "pos = " << '(' << X() << ',' << Y() << ')' << std::endl;
	if (key)std::cout << "key exist" << std::endl;
	else std::cout << "no key" << std::endl;
}

int Player::get_HP()
{
	return this->HP;
}

void Player::set_HP(int a)
{
	this->HP = a;
}

void Player::update(Event* ev)
{
	this->HP += ev->get_HP();
	this->speed += ev->get_speed();
	if (ev->get_key())set_key();
}
void Player::set_key() {
	key = true;
}
bool Player::get_key() {
	return key;
}
void Player::check_pos() {
	if (Y() < 0) {
		Y(setti.Y() + Y());
	}
	else if (Y() >= setti.Y()) {Y(Y() % setti.Y()); }

	if (X() < 0) { X(setti.X() + X()); }
	else if (X() >= setti.X()) {X(X() % setti.X()); }
}

Printer Player::get_log() {
	Printer res;
	res.add("\n<player>\nPossition: ");
	res.add(point().point_to_string());
	res.add("\nHP: ");
	res.add(toString(HP));
	res.add("\nspeed: ");
	res.add(toString(speed));
	if (key) res.add("\nkey found");
	else res.add("key not found");
	return res;
}
