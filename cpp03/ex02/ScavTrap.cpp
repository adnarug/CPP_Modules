/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 10:34:21 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setHP(MAX_HP);
	setEnergy(MAX_ENERGY);
	setAtck(ATCK);
	std::cout << "Default constructor for ScavTrap: NoNamer is called." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	setHP(MAX_HP);
	setEnergy(MAX_ENERGY);
	setAtck(ATCK);
	std::cout << "Constructor for ScavTrap: " << getName() << " is called." << std::endl;
	return;
}

ScavTrap::~ScavTrap ()
{
	std::cout << "Deconstructor for ScavTrap: " << getName() <<" is called." << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy constructor for ScavTrap: "<< getName() << " is called." << std::endl;
	return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);
	return (*this);
}

void ScavTrap::guardGate (void)
{
	std::cout<<getName()<<" is guarding the gate in gatekeeper mode." << std::endl;
}

void		ScavTrap::callGuardGate(void)
{
	this->guardGate();
}

