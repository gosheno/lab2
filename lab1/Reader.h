#pragma once

class Reader {
private:
    char move;
    Point2D settings;
    int level;
public:
    Reader();
    char read_move();
    Point2D read_field_settings();
    Point2D get_settings();
    int read_level_info();

    char get_move();

};

