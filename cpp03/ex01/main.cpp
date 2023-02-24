/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:13:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/24 16:57:12 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap Clappy("Clappy");

	Clappy.attack("Sir Hammerlock");
	Clappy.takeDamage(9);
	Clappy.beRepaired(10);
	
	
	return (0);
}
