#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

#include <string>
#include <iostream>

class HumanB 
{
	public:
	HumanB(std::string weapon);
	~HumanB(void);

	void				attack (void) const;
	void				setWeapon(Weapon const & Weapon);
	std::string			getName(void) const;

	private:
	Weapon const		*_Weapon;
	std::string 		_name;
};
#endif