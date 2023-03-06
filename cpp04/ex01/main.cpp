/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:06:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/06 12:12:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#define ZOO_SIZE 4



int main ()
{
	std::cout << "*************** TEST 1 ***************" << std::endl;
	{
		std::cout << "*************** Construction Chain ***************" << std::endl;
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		std::cout << "*************** Objects'methods ***************" << std::endl;
		i->makeSound();
		j->makeSound();
		std::cout << "*************** Deconstruction ***************" << std::endl;
		delete j;
		delete i;
	}
		system ("leaks animals_with_brain");
	std::cout << std::endl << std::endl;
	std::cout << "*************** TEST 2 ***************" << std::endl;
	{
		size_t i = 0;
		std::cout << "*************** Construction Chain ***************" << std::endl;
		Animal *zoo[ZOO_SIZE];

		while ( i < ZOO_SIZE)
		{
			if (i % 2 == 0)
				zoo[i] = new Dog();
			else
				zoo[i] = new Cat();
			i++;
		}
		std::cout << "*************** Testing the zoo sounds ***************" << std::endl;
		for (i = 0; i < ZOO_SIZE; i++)
		{
			std::cout << zoo[i]->getType() << " " << i << " " << std::endl;
			zoo[i]->makeSound();
		}
		for (; i < ZOO_SIZE; i++)
			delete &zoo[i];
	}
		std::cout << "*************** TEST 3 ***************" << std::endl;
	{
		std::cout << "*************** Construction Chain ***************" << std::endl;
		Dog Dog1;
		Dog Dog2(Dog1);
		Dog Dog3 = Dog1;
		Cat	Cat1;
		Cat	Cat2(Cat1);
		Cat Cat3 = Cat1;
		
		std::cout << "*************** Testing deep copies for Dogs and Cats ***************" << std::endl;
		std::cout << "*************** Copy Constr: " << std::endl;
		Dog2.getBrain()->printIdeas();
		std::cout<< "**" << std::endl;
		Cat2.getBrain()->printIdeas();
		std::cout << "*************** Assignment oper: " << std::endl;
		Dog3.getBrain()->printIdeas();
		std::cout<< "**" << std::endl;
		Cat3.getBrain()->printIdeas();
		std::cout << "*************** Deconstruction ***************" << std::endl;
	}
	system ("leaks animals_with_brain");
	return 0;
}