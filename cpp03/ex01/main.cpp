/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 00:39:17 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


//TODO: where to add protected!?
int main (void)
{
	std::cout << "***************Constructing***************" << std::endl;
	ClapTrap Clappy("Clappy");
	ScavTrap Scavvy("Scavvy");
	ScavTrap Scavvy2(Scavvy);

	std::cout << "***************Executing Functions***************" << std::endl;
	Scavvy.callGuardGate();
	Scavvy.attack("Jack");
	Scavvy.beRepaired(5);
	Scavvy.takeDamage(9);
	Scavvy.beRepaired(10);
	Scavvy2.attack("Jackie");

	return (0);
}
