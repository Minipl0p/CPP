
#include "Point.hpp"

Point::Point()								: x(0), y(0)	{};

Point::Point(const float a, const float b)	: x(a), y(b)	{};

Point::Point(const Point& cpy)				: x(cpy.x), y(cpy.y) {};

Point&	Point::operator=(const Point& cpy) { (void)cpy; return *this; };

Point::~Point() {};

Fixed	Point::getX() const	{return x; }
Fixed	Point::getY() const	{return y; }

bool	Point::operator==(const Point& src) const { return (this->x == src.x && this->y == src.y); }
