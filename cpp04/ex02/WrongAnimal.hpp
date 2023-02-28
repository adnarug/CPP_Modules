#ifndef WRONGAAnimal_HPP
#define WRONGAAnimal_HPP

#include <iostream>

class WrongAAnimal
{
	public:
		WrongAAnimal(void);
		WrongAAnimal(WrongAAnimal const &src);
		virtual ~WrongAAnimal(void);
		WrongAAnimal &operator=(WrongAAnimal const &rhs);

		virtual void makeSound(void) const;
		virtual void setType(std::string const &type);
		virtual std::string getType(void) const;

	protected:
		std::string _type;
};

#endif