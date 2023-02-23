/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:26:34 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/23 14:19:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point () : _x(0), _y(0)
{
    return;
}

Point::Point (float const x, float const y) : _x(x), _y(y)
{
    return;
}

Point::Point (const Point  & src)
{
    *this = src;
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

void Point::setX(Point const & x)
{
    this->_x = x;
}

void Point::setY(Point const & y)
{
    this->_y = y;
}
/**========================================================================
 *                           Arithmetic operators
 *========================================================================**/

Point Point::operator+(Point const & rhs)
{
	Point result;
	result.setX(this->getX() + rhs.getX());
    result.setY(this->getY() + rhs.getY());
	return (result);
}

Point Point::operator-(Point const & rhs)
{
	Point result;
	result.setX(this->getX() - rhs.getX());
    result.setY(this->getY() - rhs.getY());
	return (result);
}

Point Point::operator*(Point const & rhs)
{
	Point result;
	result.setX(this->getX() * rhs.getX());
    result.setY(this->getY() * rhs.getY());
	return (result);
}

Point  Point::operator=(Point const & rhs)
{
	Point result;
	result.setX(this->getX() * rhs.getX());
    result.setY(this->getY() * rhs.getY());
	return *this;
}