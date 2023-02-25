/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 23:56:26 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	std::cout << "***************Constructing***************" << std::endl;
	ClapTrap Clap;
	ClapTrap Clappy("Clappy");
	ClapTrap Chatty(Clappy);

	std::cout << "***************Executing Functions***************" << std::endl;

	Clap.attack("Handsome Jack");
	Clap.takeDamage(10);
	
	Clappy.attack("Sir Hammerlock");
	Clappy.takeDamage(9);
	Clappy.beRepaired(10);
	
	Chatty.attack("Tiny Tina");
	
	return (0);
}
