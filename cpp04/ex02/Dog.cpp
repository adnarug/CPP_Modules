/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:29:10 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/28 19:45:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal(), _brain(new Brain)
{
	setType("Dog");
	Dog::setIdeas(getBrain()->getNumIdeas());
	std::cout << "Deafult constructor for Dog is called" << std::endl;
	return; 
}

Dog::Dog(Dog const &src)
{
	setType("Dog");
	std::cout << "Copy constructor for Dog is called" << std::endl;

	_brain = new Brain;
	for (size_t i = 0; i < _brain->getNumIdeas(); i++)
	{
		_brain->getIdeas()[i] = src._brain->getIdeas()[i];
	}
	return ;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Deafult de-constructor for Dog is called" << std::endl;
	return ;
}

Dog& Dog::operator=(Dog const& rhs)
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

void Dog::makeSound(void) const
{
	std::cout << "Dog: Gav-woof" << std::endl;
}

void Dog::setIdeas (size_t i)
{
	for (size_t z = 0; z < i; z++)
	{
		getBrain()->getIdeas()[z] = "Idea of a Dog " + std::to_string(z);
	}
	return ;
}
Brain *Dog::getBrain() const
{
	return (this->_brain);
}