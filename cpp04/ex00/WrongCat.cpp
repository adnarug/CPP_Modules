/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:26:25 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/27 14:13:50 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	setType("WrongCat");
	std::cout << "Deafult constructor for WrongCat is called" << std::endl;
	return; 
}

WrongCat::WrongCat(WrongCat const &src)
{
	setType("WrongCat");
	std::cout << "Copy constructor for WrongCat is called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "Deafult de-constructor for WrongCat is called" << std::endl;
	return ;
}

WrongCat& WrongCat::operator=(WrongCat const& rhs)
{
	if (this == &rhs)
		return (*this);
	this->_type = rhs.getType();
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: I speak human tongues..ehm, maybe I am Wrong?" << std::endl;
}