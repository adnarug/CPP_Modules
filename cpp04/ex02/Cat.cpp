/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:26:25 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/28 19:45:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	setType("Cat");
	Cat::setIdeas(getBrain()->getNumIdeas());
	std::cout << "Deafult constructor for Cat is called" << std::endl;
	return; 
}

Cat::Cat(Cat const &src)
{
	setType("Cat");
	std::cout << "Copy constructor for Cat is called" << std::endl;	
	_brain = new Brain;
	for (size_t i = 0; i < _brain->getNumIdeas(); i++)
	{
		_brain->getIdeas()[i] = src._brain->getIdeas()[i];
	}
	return ;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Deafult de-constructor for Cat is called" << std::endl;
	return ;
}

Cat& Cat::operator=(Cat const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	delete _brain;
	_brain = new Brain;
	for (size_t i = 0; i < _brain->getNumIdeas(); i++)
	{
		_brain->getIdeas()[i] = rhs._brain->getIdeas()[i];
	}
	return (*this);
}

void Cat::setIdeas (size_t i)
{
	for (size_t z = 0; z < i; z++)
	{
		getBrain()->getIdeas()[z] = "Idea of a Cat " + std::to_string(z);
	}
	return ;
}
Brain *Cat::getBrain()
{
	return (this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << "Cat: Meow-myay" << std::endl;
}
