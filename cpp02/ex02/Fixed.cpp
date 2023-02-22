/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:18:07 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/22 14:46:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/**------------------------------------------------------------------------
 *                           Co/Deconstructors
 *------------------------------------------------------------------------**/
Fixed::Fixed() : _fixpointValue(0)
{
	std::cout<<"Default constructor called" << std::endl;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout<<"Int constructor called" << std::endl;
	this->_fixpointValue = num << this->_numbFracBits;
}

Fixed::Fixed(float const num)
{
	std::cout<<"Float constructor called" << std::endl;
	this->_fixpointValue = round(num * (double)( 1 << this->_numbFracBits));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
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
 *                           Operators overloads
 *========================================================================**/
Fixed&  Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
		this->_fixpointValue = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

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