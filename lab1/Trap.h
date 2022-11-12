#pragma once
#include "Level.h"
class Trap :
    public Level
{
public:
    Trap() {
        init();
    }
    void init() override;
    void set_level_map(Field& fl) override;
    void proc(Field& fl, Player& pl)override;
};

