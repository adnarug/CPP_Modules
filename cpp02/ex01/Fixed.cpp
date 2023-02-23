/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:18:07 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/23 09:42:16 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixpointValue(0)
{
	std::cout<<"Default constructor called" << std::endl;
}

Fixed::~Fixed() {
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
	this->_fixpointValue = roundf(num * (double)( 1 << this->_numbFracBits));
}

int Fixed::getRawBits (void) const
{
	return (Fixed::_fixpointValue);
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed&  Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;	
	if (this != &rhs)
		this->_fixpointValue = rhs.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	Fixed::_fixpointValue = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

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