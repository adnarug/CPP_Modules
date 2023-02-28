/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:10:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/27 14:08:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal () : _type("NoName_Animal")
{
	std::cout << "Deafult constructor for Animal is called" << std::endl;
	return; 
}

Animal::Animal (Animal const &src)
{
	std::cout << "Copy constructor for Animal is called" << std::endl;
	*this = src;
	return ;
}

Animal& Animal::operator=(Animal const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string const & type) 
{
	_type = type;
	return;
}

void Animal::makeSound(void) const
{
	std::cout << "Generic animalistic sound: Raw-mewo" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Deafult de-constructor for Animal is called" << std::endl;
	return ;
}