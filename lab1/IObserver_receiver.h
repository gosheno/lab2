#pragma once

class IObserver_receiver {
public:
	virtual void updtx(Point2D pos = Point2D(-1, -1)){};
	virtual Printer get_log() = 0;
};
