#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat &operator=(Cat const &rhs);
        virtual void setIdeas (size_t i);
		virtual void makeSound(void) const;
		Brain *getBrain();
	private:
		Brain *_brain;
};

#endif