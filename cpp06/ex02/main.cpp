/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:13:55 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/17 14:23:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() 
{
	int i = 0;
	std::cout << "randomly generated: ";
	 i = std::rand() % 3;
	if (i == 0)
	{
		std::cout << "A";
		return new A();
	}
	else if (i==1)
	{
		std::cout << "B";
		return new B();
	}
	else if (i==2)
	{
		std::cout << "C";
		return new C();
	}
	else
		return NULL;
}

void identify(Base* p)
{
	std::cout << "By pointer: ";
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cerr << "bad cast" << std::endl;
}

void identify(Base& p)
{
	std::cout << "By reference: ";
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception& err) 
	{
	}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception& err) 
	{
	}
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception& err) 
	{
		std::cerr << "bad cast" << std::endl;
		return ;
	}
 }
 
int main() 
{
	std::srand(std::time(NULL));
	Base *ptr = NULL;
	ptr = generate();
	std::cout << " - pointer" << std::endl;
	Base* tmp = generate();
	Base& ref = *tmp;
	std::cout << " - reference" << std::endl;
	identify(ptr);
	identify(ref);
	delete ptr;
	delete tmp;
	// system("leaks identifier");
	return 0;
}
