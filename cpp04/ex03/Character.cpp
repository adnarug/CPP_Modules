/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:00:22 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/03 13:59:04 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character() : _name("NoName"), _slotsEmpty(4)
{	
	for (size_t i = 0; i < 4; i++)
		slots[i] = NULL;
}

Character::Character( const Character & src )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (src.slots[i] != NULL)
			this->slots[i] = src.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name), _slotsEmpty(4)
{
	for (size_t i = 0; i < 4; i++)
		slots[i] = NULL;

}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->slots[i] != NULL)
			delete this->slots[i];
	}
}  

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (this->slots[i] != NULL)
				delete this->slots[i];
		}
		if (this != &rhs)
		{
			this->_name = rhs.getName();
			for (size_t i = 0; i < 4; i++)
			{
				if (rhs.slots[i] != NULL)
					this->slots[i] = rhs.slots[i]->clone();
				else
					this->slots[i] = NULL;
			}
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "The slot " << idx << " is out of range" << std::endl;
		return ;
	}
	if (this->slots[idx] == NULL)
	{
		std::cerr << "The slot " << idx << " is empty" << std::endl;
		return ;
	}
	this->slots[idx]->use(target);
}

void Character::equip (AMateria *m)
{
	size_t i;
	if (_slotsEmpty == 0)
	{
		std::cerr << "No more slots available" << std::endl;
		return ;
	}
	for (i = 0; slots[i] != NULL && i < 4; i++);
	if ( i == 4)
		return ;
	slots[i] = m;
	_slotsEmpty--;
	if (m != NULL && VERBOSE == 1)
		std::cout << this->getName() << " equipped " << m->getType() << " in slot num: " << i << std::endl;
	return;
}

void Character::unequip(int idx)
{
	if (this->slots[idx] == NULL && (idx < 0 || idx > 3))
		std::cerr << "The slot " << idx << " cannot be unequipped" << std::endl;
	else
		slots[idx] = NULL;

}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/



std::string const &Character::getName(void) const
{
	return (this->_name);
}
/* ************************************************************************** */