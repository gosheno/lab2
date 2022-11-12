#include "Mediator.h"

Mediator::Mediator(Point2D set) :level(new Level_0){};
Point2D Mediator::get_step_comand(char w)
{
    switch (w) {
    case 'w':
    case 'W':
        this->step_comand = Point2D(1, 0);
        break;
    case 'd':
    case 'D':
        this->step_comand = Point2D(0, 1);
        break;
    case 's':
    case 'S':
        this->step_comand = Point2D(-1, 0);
        break;
    case 'a':case 'A':
        this->step_comand = Point2D(0, -1);
        break;
    case 'e':case 'E':
        this->step_comand = Point2D(0, 0);
        break;
    case 'r':case 'R':
        this->step_comand = Point2D(0, 0);
        break;
    default:
        this->step_comand = Point2D(0, 0);
        std::cout << "wrong movement" << std::endl;
        break;
    }
    return step_comand;
}

Point2D Mediator::get_step_comand()
{
    return this->step_comand;
}

Point2D Mediator::get_settings_info(Point2D req)
{
    Point2D st;
    bool inp = true;
    while (inp) {
        inp = false;
        st = read_field_settings();
        if (st.X() < req.X()) { std::cout << "wrong input: min height = " << req.X()<<std::endl; inp = true; }
        if (st.Y() < req.Y()) { std::cout << "wrong input: min widh = " << req.Y() << std::endl; inp = true;}

    }
    return st;
}

Level* Mediator::get_level() {
    int level = read_level_info();
    switch (level) {
    case 0:
        this->level = new Level_0;
        std::cout << "<<level 0>>\n";
        break;
    case 1:
        this->level = new Level_1;
        std::cout << "<<level 1>>\n";
        break;

    default:
        std::cout << "wrong level\n" << std::endl;
        this->level = new Level_1;
        std::cout << "<<level 1>>\n";
        break;
    }
    return this->level;
}
