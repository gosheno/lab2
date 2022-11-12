
class IObserver_sender
{
public:
    virtual void receiver_add(IObserver_receiver* o) = 0;
    virtual void receiver_remove(IObserver_receiver* o) = 0;
};

