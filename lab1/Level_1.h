#pragma once
#include "Level.h"
#include "Skin_key.h"
class Level_1:
    public Level
{
public:
    Level_1() {
        init();
        set_limit_req(Point2D(5, 5));
    }
    void init() override;
    void set_level_map(Field& fl);
    void proc(Field& fl, Player& pl)override;
};

