#include "Reader.h"

Reader::Reader():move('w') {}
char Reader::read_move()
{
        this->move = _getch();
        std::cin.clear();
        return this->move;
}
char Reader::get_move()
{
    return this->move;
}
 
Point2D Reader::read_field_settings()
{
    std::cout << "input map setting: x, y"<<std::endl;
    int  a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    this->settings = Point2D(a, b);
    return settings;
}
Point2D Reader::get_settings() {
    return settings;
}

int Reader::read_level_info() {
    std::cout << "input game level: ";
    std::cin >> this->level;
    std::cout << std::endl;
    system("cls");
    return this->level;

}
