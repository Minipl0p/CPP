
#pragma once

#include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& cpy);
		Point&	operator=(const Point& cpy);
		~Point();

		bool	operator==(const Point& copy) const;
		Fixed	getX() const;
		Fixed	getY() const;

};
