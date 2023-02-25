#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
# include <iostream>

class Point 
{
	public:
	Point (void);
	Point (Point const & src);
	Point (const float x, const float y);
	Point (int const x, int const y);
	Point(Fixed const& x, Fixed const& y);
	~Point (void);
	
	Point operator*(Point const & rhs) const;
	Point operator-(Point const & rhs) const ;
	Point operator+(Point const & rhs) const ;
	Point operator=(Point const & rhs) const;
	Point operator/(Point const & rhs) const;

	Fixed getX() const;
	Fixed getY() const;
	void setX(Fixed const & x);
	void setY(Fixed const & y);

	private:
	Fixed _x;
	Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif