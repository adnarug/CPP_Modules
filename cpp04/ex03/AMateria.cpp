/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:42:04 by pguranda          #+#    #+#             */
/*   Updated: 2023/03/06 11:42:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria(): _type("RandomMateria")
{
}

AMateria::AMateria( const AMateria & src )
{
	*this = src;
}

AMateria::AMateria(std::string const & type)
{
	_type = type;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::setType(std::string const & type)
{
	_type = type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

/* ************************************************************************** */