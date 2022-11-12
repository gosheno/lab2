#pragma once

class AObserver_sender :
    public IObserver_sender, public Point2D
{
private:
    std::vector <IObserver_receiver*> observers;
public:
    AObserver_sender();
    virtual void notify_movement();
    virtual Printer take_log();
    virtual void receiver_add(IObserver_receiver* o)override;
    virtual void receiver_remove(IObserver_receiver* o)override;
};

