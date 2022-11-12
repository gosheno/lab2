#include "AObserver_sender.h"
AObserver_sender::AObserver_sender()
{
	observers = std::vector<IObserver_receiver*>();
}

void AObserver_sender::notify_movement()
{
	for (auto el : observers) {
		el->updtx(this->point());
	}
}

Printer AObserver_sender::take_log() {
	Printer logs;
	for (auto el : observers) {
		logs.add(el->get_log());
		logs.add("\n");
	}
}

void AObserver_sender::receiver_add(IObserver_receiver* o)
{
	observers.push_back(o);
}

void AObserver_sender::receiver_remove(IObserver_receiver* o)
{
	observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());

}
