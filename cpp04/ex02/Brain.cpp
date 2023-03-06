/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:03:08 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/06 12:18:42 by pguranda         ###   ########.fr       */
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
	size_t  num_of_ideas = 3;
	std::cout << "Printing top 3 (or less) ideas: " << std::endl;
	if (getNumIdeas() < num_of_ideas)
	{
		num_of_ideas = getNumIdeas();
	}
	for (size_t i = 0; i < num_of_ideas; i++)
	{
		std::cout << getIdeas()[i] << std::endl;
	}
	return ;
}