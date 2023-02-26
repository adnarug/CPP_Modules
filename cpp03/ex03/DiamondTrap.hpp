#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap 	(void);
		DiamondTrap 	(std::string const &name);
		~DiamondTrap	(void);
		DiamondTrap		(DiamondTrap const &src);
		DiamondTrap		&operator=(DiamondTrap const &rhs);
		using			ScavTrap::attack;
		void			whoAmI(void);
		void 			setName(std::string const name);
	private:
		std::string		_name;
};

#endif