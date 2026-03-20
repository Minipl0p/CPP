
#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 3);
	Point p(2, 0);

	
	if (bsp(a, b, c, p))
		std::cout << "P is INSIDE of the triangle.\n";
	else
		std::cout << "P is ON the edge or is the VERTEX or OUTSIDE the triangle.\n";

	return 0;
}

