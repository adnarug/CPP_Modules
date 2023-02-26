/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:26:25 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 14:30:24 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Deafult constructor for Cat is called" << std::endl;
	return; 
}

Cat::Cat(Cat const &src)
{
	*this = src;
	return ;
}

Cat::Cat(std::string const & type) : Animal(type)
{
	return ;
}

Cat::~Cat()
{
	std::cout << "Deafult de-constructor for Cat is called" << std::endl;
	return ;
}

Cat& Cat::operator=(Cat const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat sound: Meow" << std::endl;
}