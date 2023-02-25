/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:26:34 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/24 11:27:57 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point () : _x(0), _y(0)
{
	return;
}

Point::Point(Fixed const& x, Fixed const& y) : _x(x), _y(y) 
{ 
	return; 
}

Point::Point(Point const& src) 
{ 
	this->_x = src.getX();
	this->_y = src.getY();
	return; 
}

Point::Point (float const x, float const y) : _x(x), _y(y)
{
	return;
}

Point::Point (int const x, int const y) : _x(x), _y(y)
{
	return;
}

Point::~Point ()
{
	return;
}


Fixed Point::getX (void) const
{
	return (this->_x);
}

Fixed Point::getY (void) const
{
	return (this->_y);
}

void Point::setX(Fixed const & x)
{
	this->_x = x;
}

void Point::setY(Fixed const & y)
{
	this->_y = y;
}
/**========================================================================
 *                           Arithmetic operators
 *========================================================================**/

Point Point::operator+(Point const & rhs) const
{
	Point result;
	result.setX(this->getX() + rhs.getX());
	result.setY(this->getY() + rhs.getY());
	return (result);
}

Point Point::operator-(Point const & rhs) const
{
	Point result;
	result.setX(this->getX() - rhs.getX());
	result.setY(this->getY() - rhs.getY());
	return (result);
}

Point Point::operator*(Point const & rhs) const
{
	Point result;
	result.setX(this->getX() * rhs.getX());
	result.setY(this->getY() * rhs.getY());
	return (result);
}

Point Point::operator=(Point const & rhs) const
{
	Point result;
	result.setX(this->getX() * rhs.getX());
	result.setY(this->getY() * rhs.getY());
	return *this;
}
