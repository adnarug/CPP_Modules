#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define MAX_HP 100
#define MAX_ENERGY 50
#define ATCK 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap 	(void);
		ScavTrap 	(std::string const &name);
		~ScavTrap	(void);
		ScavTrap	(ScavTrap const &src);
		ScavTrap	&operator=(ScavTrap const &rhs);

		void		callGuardGate(void) ;
	private:
		void		guardGate (void);

};

#endif