/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:06:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/26 14:31:28 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main ()
{
	Animal Animal;
	Dog Doggy("Barbos");
	Cat Kitty("Kitty");
	
	Animal.makeSound();
	Doggy.makeSound();
	Kitty.makeSound();
	
	return 0;
}