/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:21:50 by pguranda          #+#    #+#             */
/*   Updated: 2023/02/25 13:46:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("NoName"), _hp(10), _energy(10), _atck(0)
{
	std::cout << "Default constructor for" << getName() << " is called." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name, int hp, int energy, int atck) : _name(name), _hp(hp), _energy(energy), _atck(atck)
{
	std::cout << "Constructor for " <<_name << " is called." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hp(10), _energy(10), _atck(0)
{
	std::cout << "Constructor for " << name << " is called." << std::endl;
	return;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "Deconstructor for " << this->_name <<" is called." << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &src) : _name(src._name), _hp(src._hp), _energy(src._energy), _atck(src._atck)
{
	std::cout << "Copy constructor is called." << std::endl;
	return ;
}


ClapTrap &ClapTrap::operator=(ClapTrap const &  rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hp = rhs._hp;
		_energy = rhs._energy;
		_atck = rhs._atck;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " has no hp and cannot attack." << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << this->_name << " has no energy to attack." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << target << \
		", causing " << this->_atck << " points of damage!" << std::endl;
	this->_energy -= 1;
}

//TODO: what if dmg is > than hp
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " has no hp." << std::endl;
		return ;
	}

	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0)
		std::cout << this->_name << " was killed."<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << this->_name << " has no hp. Nothing left to repair." << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << this->_name << " has no energy left for the repairs." << std::endl;
		return ;
	}
	if (_hp + amount > 10)
	{
		amount = 10 - this->_hp;
		this->_hp = 10;
	}
	else
		this->_hp += amount;
	std::cout << this->_name << " repaired itself by " << amount << std::endl;
	this->_energy -= 1;
}

//Getters and Setters


int			ClapTrap::getHP(void) const
{
	return _hp;
}

int			ClapTrap::getEnergy(void) const
{
	return _energy;
}

int			ClapTrap::getAtck(void) const
{
	return _atck;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

void		ClapTrap::setName(std::string const name)
{
	this->_name = name;
}
void		ClapTrap::setHP(unsigned int const amount)
{
	_hp = amount;
}
void 		ClapTrap::setEnergy(unsigned int const amount)
{
	_energy = amount;
}
void		ClapTrap::setAtck(unsigned int const amount)
{
	_atck = amount;
}