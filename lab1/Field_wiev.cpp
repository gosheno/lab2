#pragma once
#include "Field_wiev.h"

Field_wiev::Field_wiev(Field& f) :field(f){}

Field_wiev Field_wiev::set_field(Field& f)
{
    field = f;
    return *this;
}

void Field_wiev::print()
{
    this->params = field.point();
    this->map = field.get_map();
    for (int i = 0; i < params.Y() * 2+2; i++)std::cout << '_';
    std::cout << std::endl;
    for (int i = params.X() - 1; i >= 0; i--) {

        std::cout << '|';
        for (int j = 0; j < params.Y(); j++) {
            std::cout << map[i][j].get_skin() << ' ';
        }
        std::cout << '|';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Field_wiev::operator=(const Field_wiev& other) {
    this->field = other.field;
}

