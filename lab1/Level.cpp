#include "Level.h"

int Level::get_iter()
{
	return num;
}
void Level::iter()
{
	this->num++;
}
Point2D Level::get_limit_req()
{
	return limit_req;
}
void Level::set_limit_req(Point2D limit) {
	limit_req = limit;
}
void Level::set_limit(Point2D lim) {
	this->limit = lim;
}
Point2D Level::get_limit() {
	return this->limit;
}
