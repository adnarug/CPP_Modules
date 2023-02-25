/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamonTrap.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 14:35:15 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap("NoName Scav"), FragTrap ("NoName Frag")
{
	
	std::cout << "Default constructor for DiamondTrap: NoNamer is called." << std::endl;
	setHP(FragTrap::getHP());
	ClapTrap::s(ScavTrap::getEnergy());
	setAtckDmg(FragTrap::getAtck());

	return;
}

DiamondTrap::DiamondTrap(std::string const name) : ScavTrap(name), FragTrap(name)
{
	std::cout << "Constructor for " << ClapTrap::getName() << " is called." << std::endl;
	return;
}

DiamondTrap::~DiamondTrap ()
{
	std::cout << "Deconstructor for DiamondTrap: " << getName() <<" is called." << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy constructor for DiamondTrap: "<< getName() << " is called." << std::endl;
	return ;
}

void DiamondTrap::whoAmI(void)
{
	std::cout<<getName()<<" gives high five!" << std::endl;
}
