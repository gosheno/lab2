#include "App.h"

void App::start()
{
    contr.Field_link().update_field();
    printer.add("to move use <WASD> without ENTER");
    printer.add("Press <enter> to start game" );
    printer.add("Press <e> to exit, <r> to reboot game");
    printer.print();
    char temp = _getch();
    if (temp != 'e') {
        game_cycle();
    }
    else {
        printer.add("<<end>>");
    }
}

void App::reboot()
{
    Controller cr = Controller();
    contr = cr;
    fw.set_field(contr.Field_link());
    start();
}

void App::game_cycle()
{
    
    Printer& prt = printer;
    int last_hp = contr.get_player().get_HP();
    char retry = '\n';
    do {
        system("cls");
        if (contr.get_mediator().get_move() == 'r') {
            printer.add("<<reboot>>");
            break;
        }
        contr.get_player().get_stat_info();

        if (contr.check_player_HP())contr.set_end();

        if (contr.player_link().get_HP() < last_hp) {
            last_hp = contr.get_player().get_HP();
            printer.add("ough, it hurts!!!");
        }

        if (contr.get_player().get_HP() < 1) {
            printer.add("<<bruh you killed me>>");
            system("cls");
            break;
        }

        fw.print();
        printer.print();
        contr.player_make_step(prt);
    } while (!(contr.get_end()));
    system("cls");
    printer.print();
    if (contr.get_mediator().get_move() != 'r') {
        printer.add("You finished level");
        printer.add("press eny key to stop and exit game\nor");
        printer.add("press <r> to  restart");
        printer.print();
        retry = _getch();
        if (retry == 'r')reboot();
        else {
            system("cls");
            contr.get_player().get_stat_info();
            fw.print();
            printer.add("<<end>>\n");
            printer.print();
        }
    }
    else reboot();
}
