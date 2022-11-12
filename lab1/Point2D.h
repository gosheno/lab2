#pragma once
#include "other.h"
class Point2D {
private:
    int x;
    int y;
public:
    Point2D(int x = 0, int y = 0);
    virtual int X();
    virtual void X(int x);
    virtual int Y();
    virtual void Y(int y);
    virtual void point(int x, int y);
    virtual void point(Point2D p);
    virtual Point2D point();
    virtual Point2D operator + (Point2D c2);
    virtual Point2D operator * (int c2);
    virtual Point2D operator * (Point2D c2);
    virtual int operator == (Point2D c2);
    virtual Point2D operator - (Point2D c2);
    virtual std::string point_to_string();
};