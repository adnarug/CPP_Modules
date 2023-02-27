#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal &operator=(Animal const &rhs);

		virtual void makeSound(void) const;
		void setType(std::string const &type);
		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif