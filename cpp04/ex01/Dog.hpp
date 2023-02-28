#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog(void);
        Dog(Dog const &src);
        ~Dog(void);
        Dog &operator=(Dog const &rhs);
        void makeSound(void) const;
        virtual void setIdeas (size_t i);
        Brain *getBrain(void) const;

    private:
        Brain *_brain;
};
#endif