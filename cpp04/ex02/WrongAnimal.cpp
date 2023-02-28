/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:10:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/27 14:08:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAAnimal::WrongAAnimal () : _type("NoName_WrongAAnimal")
{
	std::cout << "Deafult constructor for WrongAAnimal is called" << std::endl;
	return; 
}

WrongAAnimal::WrongAAnimal (WrongAAnimal const &src)
{
	std::cout << "Copy constructor for WrongAAnimal is called" << std::endl;
	*this = src;
	return ;
}

WrongAAnimal& WrongAAnimal::operator=(WrongAAnimal const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

std::string WrongAAnimal::getType() const
{
	return (this->_type);
}

void WrongAAnimal::setType(std::string const & type) 
{
	_type = type;
	return;
}

void WrongAAnimal::makeSound(void) const
{
	std::cout << "Generic WrongAAnimalistic sound: Hmm.. I am a wrong AAnimal, I should not speak" << std::endl;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "Deafult de-constructor for WrongAAnimal is called" << std::endl;
	return ;
}