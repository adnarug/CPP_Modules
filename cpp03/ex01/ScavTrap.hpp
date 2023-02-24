#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ClapTrap 	(void);
		ClapTrap 	(std::string name);
		~ClapTrap	(void);
		ClapTrap	(ClapTrap const &ClapTrap);
		ClapTrap	&operator=(ClapTrap const & rhs);
		void		attack		(const std::string &target);
		void		takeDamage	(unsigned int amount);
		void		beRepaired	(unsigned int amount);
	private:

};

#endif