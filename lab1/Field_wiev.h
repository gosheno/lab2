#pragma once
#include <vector>
#include <iostream>
#include "Field.h"

class Field_wiev {
    std::vector<std::vector<Cell>> map;
    Field& field;
    Point2D params;
public:
    Field_wiev(Field& f);
    Field_wiev set_field(Field& f);
    void operator=(const Field_wiev& other);
    void print();

};