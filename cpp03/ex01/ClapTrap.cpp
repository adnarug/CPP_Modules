#include "ClapTrap.hpp"

//	De/Constructors
ClapTrap::ClapTrap() : _name("NoName"), _hp(100), _energy(100), _atck(0)
{
	std::cout << "Default constructor for ClapTrap: NoNamer is called." << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hp(100), _energy(100), _atck(0)
{
	std::cout << "Constructor for " << name << " is called." << std::endl;
	return;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "Deconstructor for " << _name <<" is called." << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const &src) : _name(src._name), _hp(src._hp), _energy(src._energy), _atck(src._atck)
{
	std::cout << "Copy constructor for ClapTrap is called." << std::endl;
	return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(ClapTrap const &  rhs)
{
	if (this == &rhs)
		return (*this);
	_name = rhs._name;
	_hp = rhs._hp;
	_energy = rhs._energy;
	_atck = rhs._atck;
	return (*this);
}

//Core functions
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
	if (this->_hp >= 100)
	{
		std::cout << this->_name << " full hp. No need for repair." << std::endl;
		return ;
	}
	if (this->_energy <= 0)
	{
		std::cout << this->_name << " has no energy left for the repairs." << std::endl;
		return ;
	}
	if (_hp + amount > 100)
	{
		std::cout << "Limiting repair to the maximum HP.. ";
		amount = 100 - this->_hp;
		this->_hp = 100;
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