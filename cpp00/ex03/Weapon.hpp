#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	public:

	Weapon(std::string weapon);
	~Weapon(void);

	std::string 	getType(void) const;
	void			setType(std::string weapon);
	
	private:
	std::string		_type;
};

#endif