#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
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