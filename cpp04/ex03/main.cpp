/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:59:59 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/06 12:02:18 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>
#include <unistd.h>


int main ()
{
	{
		std::cout << "*****TEST based on subject*****" << std::endl;
		IMateriaSource * src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		
		if (VERBOSE)
			std::cout<<std::endl;
		delete bob;
		delete me;
		delete src;
		if (VERBOSE)	
			std::cout<<std::endl;
		system ("leaks game");
	}
		std::cout<<std::endl<< std::endl << std::endl;
	{
		std::cout << "*****My test*****" << std::endl;
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("Bobby McGee");
		ICharacter* ronny = new Character("RawKnee");
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp;
		
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		me->equip(tmp);
		src->learnMateria(new Ice());
		tmp = src->createMateria("ice");
		bob->equip(tmp);
		tmp = src->createMateria("cure");
		ronny->equip(tmp);
		ronny->equip(new Cure());
		ronny->unequip(1);
		ronny->unequip(0);
		ronny->unequip(1);
		ronny->equip(new Ice());
		
		me->use(0, *bob);
		bob->use(0, *ronny);
		ronny->use(0, *me);
		
		if (VERBOSE)
			std::cout<<std::endl;
		delete bob;
		delete me;
		delete src;
		delete ronny;
		if (VERBOSE)
			std::cout<<std::endl;
		system ("leaks game");
	}
	return (0);
}