/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 12:49:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scavenger", 100, 50, 20)
{
	std::cout << "Default constructor for ScavTrap: NoNamer is called." << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name, 100, 50, 20)
{
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


void ScavTrap::guardGate (void)
{
	std::cout<<getName()<<" is guarding the gate in the Gatekeeper mode" << std::endl;
}

void		ScavTrap::callGuardGate(void)
{
	this->guardGate();
}

