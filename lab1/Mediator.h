#pragma once

class Mediator :public Reader {
private:
    Point2D step_comand;
    Level* level;
public:
    Mediator(Point2D seti = Point2D(0, 0));
    Point2D get_step_comand(char w);
    Level* get_level();
    Point2D get_settings_info(Point2D req);
    Point2D get_step_comand();
};