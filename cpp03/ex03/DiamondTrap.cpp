/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 23:35:29 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap ("NoName Frag"), ScavTrap("NoName Scav")
{
	std::cout << "Default constructor for Diamond Trap: NoNamer is called." << std::endl;
	setHP(FragTrap::getHP());
	setEnergy(ScavTrap::getEnergy());
	setAtck(FragTrap::getAtck());
	return;
}


DiamondTrap::DiamondTrap(std::string const name) :  ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "Constructor for Diamond Trap: " << this->_name << " is called." << std::endl;
	setHP(FragTrap::getHP());
	setEnergy(ScavTrap::getEnergy());
	setAtck(FragTrap::getAtck());
	return;
}

DiamondTrap::~DiamondTrap ()
{
	std::cout << "Deconstructor for DiamondTrap: " << this->_name <<" is called." << std::endl;
}

DiamondTrap::DiamondTrap (DiamondTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy constructor for DiamondTrap: "<< this->_name << " is called." << std::endl;
	return ;
}

void DiamondTrap::whoAmI(void)
{
	std::cout<<"The name of the DiamondTrap is: "<<this->_name <<" and its ClapTrap name is: "<< ClapTrap::getName()<< std::endl;
}
