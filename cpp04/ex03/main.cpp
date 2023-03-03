/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:59:59 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/03 14:05:05 by pguranda         ###   ########.fr       */
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
		std::cout << "*****My test*****" << std::endl;
		IMateriaSource * src = new MateriaSource();
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("Bobby McGee");
		AMateria* tmp;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());//should fail to learn
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->equip(tmp);
		me->equip(tmp);
		me->equip(tmp); // should fail to equp
		me->use(0, *bob);
		bob->equip(tmp);
		bob->use(0, *bob);
		me->unequip(2);
		std::<cerr
		delete bob;
		delete me;
		delete src;	
		system ("leaks game");

	// {
	// 	std::cout << "*****TEST based on subject*****" << std::endl;
	// 	IMateriaSource * src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);

	// 	delete bob;
	// 	delete me;
	// 	delete src;	
	// 	system ("leaks game");
	// }
	return (0);
}