#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap 	(void);
		ClapTrap 	(std::string name);
		~ClapTrap	(void);
		ClapTrap	(ClapTrap const &src);
		ClapTrap(std::string name, int hp, int energy, int atck);
		ClapTrap	&operator=(ClapTrap const & rhs);
		void		attack		(const std::string &target);
		void		takeDamage	(unsigned int amount);
		void		beRepaired	(unsigned int amount);
		std::string getName(void) const;
	private:
		std::string 	_name;
		int				_hp;
		int				_energy;
		int 			_atck;
};

#endif