/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 11:31:37 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
	std::cout << "***************Construction Chain ***************" << std::endl;
	DiamondTrap Diamondy("Diamondy");
	DiamondTrap Diamondy2;

	std::cout << "***************Executing Functions***************" << std::endl;

	Diamondy.whoAmI();
	Diamondy.attack("Sammy");
	Diamondy2.callGuardGate();
	Diamondy2.whoAmI();
	std::cout << "***************Deconstruction Chain ***************" << std::endl;
	return (0);
}
