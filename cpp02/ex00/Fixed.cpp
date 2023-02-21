/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:18:07 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/21 13:34:19 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixpointValue(0){
	std::cout<<"Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
	std::cout << "Coppy assignment operator called" << std::endl;	
	if (this != &rhs)
		this->_fixpointValue = rhs.getRawBits();
	
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	Fixed::_fixpointValue = raw;
}