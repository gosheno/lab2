#pragma once
#include "Skin.h"
#include "Field.h" 
class Level:public Skin
{
private:
	int num;
	Point2D limit_req;
	Point2D limit;
public:
	Level():num(0),limit(Point2D(10, 10)), limit_req(Point2D(0, 0)) {}
	virtual void set_level_map(Field& fl) = 0;
	virtual void iter();
	int get_iter();
	Point2D get_limit_req();
	void set_limit_req(Point2D limit);
	void set_limit(Point2D lim);
	Point2D get_limit();
};

