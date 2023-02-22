/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:08:39 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 15:43:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"


HumanB::HumanB(std::string name) : _name(name)
{
	return ;
}

HumanB::~HumanB()
{
	return ;
}


void HumanB::setWeapon(Weapon const & Weapon)
{
	this->_Weapon = &Weapon;
	return ;
}

std::string HumanB::getName() const
{
	return (this->_name);
}

void HumanB::attack() const
{
	if (!this->_Weapon->getType().empty())
		std::cout<<this->getName()<<" attacks with their "<< this->_Weapon->getType()<< std::endl;
	else
		std::cout<<this->getName()<<" pokes with his pointy finger, s/he's got no weapon "<<  std::endl;
}