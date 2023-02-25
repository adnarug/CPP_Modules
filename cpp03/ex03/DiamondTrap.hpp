#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual FragTrap,  public virtual ScavTrap
{
	public:
		DiamondTrap 	(void);
		DiamondTrap 	(std::string name);
		~DiamondTrap	(void);
		DiamondTrap		(DiamondTrap const &src);
		using			ScavTrap::attack;
		void			whoAmI(void);
		void 			setName(std::string const name);
	private:
		std::string		_name;
};

#endif