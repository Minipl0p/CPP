
#include "Point.hpp"

Fixed	sign(Point const& a, Point const& b, Point const& c)
{
	Fixed	term1 = (a.getX().toFloat() - c.getX().toFloat()) * (b.getY().toFloat() - c.getY().toFloat());
	Fixed	term2 = (b.getX().toFloat() - c.getX().toFloat()) * (a.getY().toFloat() - c.getY().toFloat());
	return (term1 - term2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return false;
	Fixed	d1 = sign(point, a, b);
	Fixed	d2 = sign(point, b, c);
	Fixed	d3 = sign(point, c, a);

	if (((d1 > 0) && (d2 > 0) && (d3 > 0)) ||
		((d1 < 0) && (d2 < 0) && (d3 < 0)))
		return true;
	return false;
}
