/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:48:19 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 12:45:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("NoName", 100, 100, 30)
{
	std::cout << "Default constructor for FragTrap: NoNamer is called." << std::endl;
	return;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name, 100, 100, 30)
{
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

void FragTrap::highFivesGuys(void)
{
	std::cout<<getName()<<" gives high five!" << std::endl;
}

void		FragTrap::callHighFives(void)
{
	this->highFivesGuys();
}

