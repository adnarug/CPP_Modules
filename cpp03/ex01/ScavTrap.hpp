#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define MAX_HP_SC 100
#define MAX_ENERGY_SC 50
#define ATCK_SC 20


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap 	(void);
		ScavTrap 	(std::string const &name);
		~ScavTrap	(void);
		ScavTrap	(ScavTrap const &src);
		ScavTrap	&operator=(ScavTrap const &rhs);
		void		callGuardGate(void) ;
	protected:
		void		guardGate (void);

};

#endif