/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:10:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/27 14:08:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal () : _type("NoName_WrongAnimal")
{
	std::cout << "Deafult constructor for WrongAnimal is called" << std::endl;
	return; 
}

WrongAnimal::WrongAnimal (WrongAnimal const &src)
{
	std::cout << "Copy constructor for WrongAnimal is called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string const & type) 
{
	_type = type;
	return;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Generic WrongAnimalistic sound: Hmm.. I am a wrong Animal, I should not speak" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Deafult de-constructor for WrongAnimal is called" << std::endl;
	return ;
}