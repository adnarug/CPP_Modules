#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define MAX_HP_FR 		100
#define MAX_ENERGY_FR	100
#define ATCK_FR			30

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap 	(void);
		FragTrap 	(std::string const &name);
		FragTrap	(FragTrap const &src);
		FragTrap	&operator=(FragTrap const &rhs);

		void		callHighFives(void) ;
		~FragTrap	(void);
	protected:
		void		highFivesGuys (void);

};

#endif