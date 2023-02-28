/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:10:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/27 14:08:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal () : _type("NoName_AAnimal")
{
	std::cout << "Deafult constructor for AAnimal is called" << std::endl;
	return; 
}

AAnimal::AAnimal (AAnimal const &src)
{
	std::cout << "Copy constructor for AAnimal is called" << std::endl;
	*this = src;
	return ;
}

AAnimal& AAnimal::operator=(AAnimal const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

std::string AAnimal::getType() const
{
	return (this->_type);
}

void AAnimal::setType(std::string const & type) 
{
	_type = type;
	return;
}

void AAnimal::makeSound(void) const
{
	std::cout << "Generic AAnimalistic sound: Raw-mewo" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Deafult de-constructor for AAnimal is called" << std::endl;
	return ;
}