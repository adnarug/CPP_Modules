/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:18:07 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/24 09:55:43 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/**------------------------------------------------------------------------
 *                           Co/Deconstructors
 *------------------------------------------------------------------------**/
Fixed::Fixed() : _fixpointValue(0)
{
}

Fixed::~Fixed() 
{
}

Fixed::Fixed(int const num)
{
	this->_fixpointValue = num << this->_numbFracBits;
}

Fixed::Fixed(float const num)
{
	this->_fixpointValue = roundf(num * (float)( 1 << this->_numbFracBits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
	return ;
}
/**========================================================================
 *                           Accessors
 *========================================================================**/
int Fixed::getRawBits (void) const
{
	return (Fixed::_fixpointValue);
}

void Fixed::setRawBits(int const raw)
{
	Fixed::_fixpointValue = raw;
}
/**========================================================================
 *                           Operators overloads -- From Ex00
 *========================================================================**/
Fixed&  Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_fixpointValue = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
/**========================================================================
 *                           Relational operators
 *========================================================================**/
bool Fixed::operator<(Fixed const & rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool Fixed::operator>(Fixed const & rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const & rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const & rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const & rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const & rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}
/**========================================================================
 *                           Arithmetic operators
 *========================================================================**/

Fixed Fixed::operator+(Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator-(Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (result);
}

Fixed Fixed::operator*(Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(this->getRawBits() * rhs.getRawBits() >> this->_numbFracBits);
	return (result);
}

Fixed Fixed::operator/(Fixed const & rhs)
{
	Fixed result;
	result.setRawBits(this->getRawBits() / rhs.getRawBits());
	return (result);
}

/**========================================================================
 *                           Incrementors / Decrementors
 *========================================================================**/

Fixed Fixed::operator++()
{
	this->_fixpointValue++;
	return (*this);
}

Fixed Fixed::operator--()
{
	this->_fixpointValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result = *this;
	++*this;
	return result;
}

Fixed Fixed::operator--(int)
{
	Fixed result = *this;
	--*this;
	return result;
}


/**========================================================================
 *                           Max and min functions
 *========================================================================**/

Fixed & Fixed::min (Fixed & num1, Fixed & num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

const Fixed & Fixed::min (const Fixed & num1, const Fixed & num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	else
		return (num2);
}

Fixed & Fixed::max (Fixed & num1, Fixed & num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
	
}
const Fixed & Fixed::max (const Fixed & num1, const Fixed & num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	else
		return (num2);
}
/**========================================================================
 *                           Other functions
 *========================================================================**/
float Fixed::toFloat(void) const
{
	float toFloat = (float) this->_fixpointValue / (float) (1 << this->_numbFracBits);
	return (toFloat) ;
}

int Fixed::toInt(void) const
{
	int toInt = this->_fixpointValue >> this->_numbFracBits;
	return (toInt);
}