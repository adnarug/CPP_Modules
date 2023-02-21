#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>


class Zombie
{
	public:
	Zombie (void);
	~Zombie (void);
	void		announce(void) const;
	void		setZombieName(std::string name);

	private:
	std::string _name;
};

Zombie*		zombieHorde( int N, std::string name);

#endif