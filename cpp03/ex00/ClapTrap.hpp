#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#define MAX_HP_CL 10
#define MAX_ENERGY_CL 10
#define ATCK_CL 0

class ClapTrap
{
	public:
		ClapTrap 	(void);
		ClapTrap 	(std::string const &name);
		~ClapTrap	(void);
		ClapTrap	(ClapTrap const &src);
		ClapTrap	&operator=(ClapTrap const &rhs);
		void		attack		(const std::string &target);
		void		takeDamage	(unsigned int amount);
		void		beRepaired	(unsigned int amount);

		std::string getName(void) const;
		int			getHP(void) const;
		int			getEnergy(void) const;
		int			getAtck(void) const;

		void		setName(std::string const name);
		void		setHP(unsigned int const amount);
		void 		setEnergy(unsigned int const amount);
		void		setAtck(unsigned int const amount);
	private:
		std::string 	_name;
		int				_hp;
		int				_energy;
		int 			_atck;
};

#endif