#pragma once


class App {
private:
    Controller  contr;
    Field_wiev fw;
    Printer printer;
public:
    App() :contr(), fw(contr.Field_link()) {}

    void start();
    void reboot();
    void game_cycle();

};