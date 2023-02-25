#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap 	(void);
		FragTrap 	(std::string name);
		~FragTrap	(void);
		FragTrap	(FragTrap const &src);
		void		callHighFives(void) ;
	private:
		void		highFivesGuys (void);

};

#endif