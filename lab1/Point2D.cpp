#include "Point2D.h"

Point2D::Point2D(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Point2D::X()
{
    return this->x;
}

void Point2D::X(int x)
{
    this->x = x;
}

int Point2D::Y()
{
    return this->y;
}

void Point2D::Y(int y)
{
    this->y = y;
}

void Point2D::point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point2D::point(Point2D p)
{
    this->x = p.X();
    this->y = p.Y();
}

Point2D Point2D::point()
{
    return Point2D(x, y);
}

Point2D Point2D::operator+(Point2D c2)
{
    Point2D sum;
    this->point(this->x + c2.x, this->y + c2.y);
    return Point2D(x, y);
}

Point2D Point2D::operator*(int c2)
{
    Point2D sum;
    point(this->x * c2, this->y * c2);
    return Point2D(X(), Y());
}

Point2D Point2D::operator*(Point2D c2)
{
    Point2D sum;
    this->point(this->x * c2.x, this->y * c2.y);
    return Point2D(X(), Y());
}

int Point2D::operator==(Point2D c2)
{
    return X() == c2.X() && Y() == c2.Y();
}

Point2D Point2D::operator-(Point2D c2)
{
    this->point(this->x - c2.x, this->y - c2.y);
    return Point2D(x, y);
}

std::string Point2D::point_to_string() {
    std::string res = "(";
    res.append(toString(x));
    res.append(", ");
    res.append(toString(y));
    res.append(")");
    return res;
}