#pragma once

class Player : public AObserver_sender, public IObserver_receiver{
private:
    int HP;
    int speed;
    bool key;
    Point2D last_move;
    Point2D cur_move;
    Point2D setti;
public:
    Player(Point2D lim = Point2D(5,5));
    void step(Point2D move = Point2D(0, 0));
    void step_back();
    void take_HP(int h);
    void take_speed(int s);
    Point2D get_last_move();
    void get_stat_info();
    int get_HP();
    void set_HP(int a);
    void set_key();
    bool get_key();
    void update(Event* ev);
    void check_pos();
    Printer get_log() override;
};
