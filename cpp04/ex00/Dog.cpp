/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:29:10 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 14:31:37 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Deafult constructor for Dog is called" << std::endl;
	return; 
}

Dog::Dog(Dog const &src)
{
	*this = src;
	return ;
}

Dog::~Dog()
{
	std::cout << "Deafult de-constructor for Dog is called" << std::endl;
	return ;
}

Dog::Dog(std::string const & type) : Animal(type)
{
	return ;
}


Dog& Dog::operator=(Dog const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Dog sound: Woof" << std::endl;
}