#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(const std::string &type) = 0;

};

#endif /* ************************************************** IMATERIASOURCE_H */