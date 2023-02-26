#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		Animal(std::string const &type);
		~Animal(void);
		Animal &operator=(Animal const &rhs);

		void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif