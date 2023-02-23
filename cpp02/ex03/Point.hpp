#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
# include <iostream>
# include <cmath>

struct vector
{
	float x;
	float y;
};

class Point 
{
	public:
	Point (void);
	Point (Point const & src);
	Point (const float x, const float y);
	~Point (void);
	Fixed getX() const;
	Fixed getY() const;
	void setX(Point const & x);
	void setY(Point const & y);

	Point operator*(Point const & rhs);
	Point operator-(Point const & rhs);
	Point operator+(Point const & rhs);
	Point operator=(Point const & rhs);

	private:
	const Fixed _x;
	const Fixed _y;
};

	bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif