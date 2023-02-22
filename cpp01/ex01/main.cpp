/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:42:33 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 16:21:01 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
	Zombie *horde = zombieHorde(10, "foo");
	
	delete [] horde ;
	// system ("leaks zombie_horde");
	return (0);
}