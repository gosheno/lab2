#pragma once
#include "Level.h"

class Level_0: public Level
{
public:
    Level_0() {
        set_limit(Point2D(10, 10));
        init();
    }
    void set_level_map(Field& fl);
    void proc(Field& fl, Player& pl)override;
    void init();
};

