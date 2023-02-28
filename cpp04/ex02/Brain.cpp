/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:08 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/28 18:26:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Deafult constructor for Brain is called" << std::endl;
	this->setIdeas(getNumIdeas());
	return; 
}

Brain::Brain ( Brain const & src )
{
	std::cout << "Copy constructor for Brain is called" << std::endl;
	*this = src;
	return ;
}

Brain::~Brain()
{

	std::cout << "Deafult de-constructor for Brain is called" << std::endl;
	return ;
}

Brain& Brain::operator=(Brain const& rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

std::string *Brain::getIdeas ()
{
	return (_ideas);
}

void Brain::setIdeas (size_t i)
{
	for (size_t z = 0; z < i; z++)
	{
		getIdeas()[z] = "Idea " + std::to_string(z);
	}
	return ;
}

size_t Brain::getNumIdeas(void) const
{
	return _numIdeas;
}

void Brain::printIdeas(void )
{

	for (size_t i = 0; i < getNumIdeas(); i++)
	{
		std::cout << getIdeas()[i] << std::endl;
	}
	return ;
}