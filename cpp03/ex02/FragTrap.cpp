/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 10:42:22 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHP(MAX_HP_FR);
	setEnergy(MAX_ENERGY_FR);
	setAtck(ATCK_FR);
	std::cout << "Default constructor for FragTrap: NoNamer is called." << std::endl;
	return;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap()
{
	setName(name);
	setHP(MAX_HP_FR);
	setEnergy(MAX_ENERGY_FR);
	setAtck(ATCK_FR);
	std::cout << "Constructor for " << getName() << " is called." << std::endl;
	return;
}

FragTrap::~FragTrap ()
{
	std::cout << "Deconstructor for FragTrap: " << getName() <<" is called." << std::endl;
}

FragTrap::FragTrap (FragTrap const &src) : ClapTrap(src)
{
	std::cout << "Copy constructor for FragTrap: "<< getName() << " is called." << std::endl;
	return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(FragTrap const & rhs)
{
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<getName()<<" gives high five!" << std::endl;
}

void		FragTrap::callHighFives(void)
{
	this->highFivesGuys();
}

