/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 11:41:56 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	std::cout << "***************Construction Chain ***************" << std::endl;
	FragTrap Fraggy("Fraggy");
	FragTrap Fraggy2;

	std::cout << "***************Executing Functions***************" << std::endl;

	Fraggy.callHighFives();
	Fraggy2.takeDamage(10);
	Fraggy2.beRepaired(10);
	Fraggy2.attack("Boras Jehnson");
	
	std::cout << "***************Deconstruction Chain ***************" << std::endl;
	return (0);
}
