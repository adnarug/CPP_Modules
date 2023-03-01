#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>
#include "AMateria.hpp"

class AMateria;

class ICharacter {
 public:
  /* constructor */
  ICharacter();

  /* copy constructor */
  ICharacter(ICharacter const& src);

  /* copy assignment operator */
  ICharacter& operator=(ICharacter const& src);

  /* destructor */
  virtual ~ICharacter();

  /* getter */
  virtual std::string const& getName() const = 0;

  /* public methods */
  virtual void equip(AMateria* m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};

#endif /* ****************************************************** ICHARACTER_H */