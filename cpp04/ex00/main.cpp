/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:06:51 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/06 12:09:28 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main ()
{
	{
	std::cout << "*************** Subject's test***************" << std::endl;
	std::cout << "*************** Construction Chain ***************" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "*************** Executing the objects ***************" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "*************** Deconstruction Chain ***************" << std::endl;
	delete j;
	delete i;
	delete meta;
	}

	std::cout << std::endl << std::endl << std::endl;
	{
	std::cout << "*************** My test***************" << std::endl;
	std::cout << "*************** Construction Chain ***************" << std::endl;
	const WrongAnimal* meta = new WrongAnimal();
	const Animal* j = new Dog();
	const WrongCat* i = new WrongCat();
	
	std::cout << "*************** Executing the objects ***************" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << "*************** Deconstruction Chain ***************" << std::endl;
	delete j;
	delete i;
	delete meta;
	}
	system ("leaks animals");
	return 0;
}