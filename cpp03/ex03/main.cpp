/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 12:46:48 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap Clappy("Clappy");
	ScavTrap Scavvy("Scavvy");
	FragTrap Fraggy ("Fraggy");

	Clappy.attack("Sir Hammerlock");
	Clappy.takeDamage(9);
	Clappy.beRepaired(10);

	Scavvy.callGuardGate();
	Scavvy.attack("Jack");

	Fraggy.callHighFives();
	Fraggy.takeDamage(10);

	return (0);
}
