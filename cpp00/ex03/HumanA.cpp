/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:08:50 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/17 12:11:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon const &Weapon_type) : _Weapon(Weapon_type), _name(name)
{
	return ;
}

HumanA::~HumanA()
{
	return ;
}

std::string HumanA::getName() const
{
	return (this->_name);
}

void HumanA::attack() const
{
	std::cout<<this->getName()<<" attacks with their "<< this->_Weapon.getType()<< std::endl;
}