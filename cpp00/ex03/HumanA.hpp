#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

#include <string>
#include <iostream>

class HumanA 
{
	public:
	HumanA(std::string weapon, Weapon const & Weapon_type);
	~HumanA(void);
	void				attack (void) const;
	std::string			getName(void) const;
	private:
	Weapon const		&_Weapon;
	std::string 		_name;
};

#endif