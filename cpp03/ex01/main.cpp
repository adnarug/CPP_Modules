/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 11:23:09 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void)
{
	std::cout << "***************Construction Chain ***************" << std::endl;
	ScavTrap Scavvy("Scavvy");
	ScavTrap Scavvy2(Scavvy);

	std::cout << "***************Executing Functions***************" << std::endl;
	Scavvy.attack("Jack");
	Scavvy.beRepaired(5);
	Scavvy.takeDamage(9);
	Scavvy.beRepaired(10);
	Scavvy2.attack("Jackie");
	Scavvy.callGuardGate();

	std::cout << "***************Deconstruction Chain ***************" << std::endl;
	return (0);
}
