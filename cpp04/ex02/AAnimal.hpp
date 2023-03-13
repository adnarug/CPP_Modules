#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual		~AAnimal(void);
		AAnimal 	&operator=(AAnimal const &rhs);

		virtual void makeSound(void) const = 0;
		void		setType(std::string const &type);
		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif