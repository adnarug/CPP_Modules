/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:42:33 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/20 15:29:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	
int main ()
{
	Zombie	Zombie_stack("Foo_on_stack");
	Zombie_stack.announce();
	
	Zombie	*Zombie_heap;
	Zombie_heap = newZombie("Foo_on_heap");
	Zombie_heap->announce();
	delete Zombie_heap;
	
	return (0);
}