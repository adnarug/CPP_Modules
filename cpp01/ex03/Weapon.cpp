/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:57:02 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/17 12:24:54 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string Weapon::getType( void ) const
{
	return (this->_type);
}

void Weapon::setType(std::string weapon)
{
	this->_type = weapon;
	return ;
}