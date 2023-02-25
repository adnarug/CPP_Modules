#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap,  virtual public ScavTrap
{
	public:
		DiamondTrap 	(void);
		DiamondTrap 	(std::string name);
		~DiamondTrap	(void);
		DiamondTrap		(DiamondTrap const &src);
		void		whoAmI(void) ;
	private:
		std::string _name;
};

#endif