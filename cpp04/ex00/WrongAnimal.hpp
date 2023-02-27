#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal(void);
		WrongAnimal &operator=(WrongAnimal const &rhs);

		virtual void makeSound(void) const;
		virtual void setType(std::string const &type);
		virtual std::string getType(void) const;

	protected:
		std::string _type;
};

#endif