#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap 	(void);
		ScavTrap 	(std::string name);
		~ScavTrap	(void);
		ScavTrap	(ScavTrap const &src);
		void		callGuardGate(void) ;
	private:
		void		guardGate (void);

};

#endif